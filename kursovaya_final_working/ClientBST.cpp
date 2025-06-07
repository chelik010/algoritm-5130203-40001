#include "ClientBST.h"
#include <iostream>
#include <fstream>
#include "StandardClient.h"
#include "GoldClient.h"
#include "PlatinumClient.h"

void ClientBST::addClient(Client* client) {
    clients[client->getId()] = client;
}

Client* ClientBST::findClientById(const std::string& id) {
    if (clients.count(id)) return clients[id];
    return nullptr;
}

Wallet* ClientBST::findWalletById(const std::string& walletId) {
    for (auto& [id, client] : clients) {
        for (auto* wallet : client->getWallets()) {
            if (wallet->getId() == walletId) return wallet;
        }
    }
    return nullptr;
}

Client* ClientBST::findClientByWalletId(const std::string& walletId) {
    for (auto& [id, client] : clients) {
        for (auto* wallet : client->getWallets()) {
            if (wallet->getId() == walletId) return client;
        }
    }
    return nullptr;
}

void ClientBST::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "❌ Не удалось открыть " << filename << " для записи\n";
        return;
    }

    for (const auto& [id, client] : clients) {
        std::string type;

        if (dynamic_cast<StandardClient*>(client)) type = "Standard";
        else if (dynamic_cast<GoldClient*>(client)) type = "Gold";
        else if (dynamic_cast<PlatinumClient*>(client)) type = "Platinum";
        else type = "Unknown";

        for (Wallet* wallet : client->getWallets()) {
            file << client->getId() << " " << client->getName() << " "
                 << type << " " << wallet->getId() << " "
                 << wallet->getBalance() << "\n";
        }
    }

    std::cout << "✅ Клиенты сохранены в файл " << filename << "\n";
}




const std::map<std::string, Client*>& ClientBST::getAllClients() const {
    return clients;
}
