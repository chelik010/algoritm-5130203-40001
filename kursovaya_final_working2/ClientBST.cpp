#include "ClientBST.h"

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

const std::map<std::string, Client*>& ClientBST::getAllClients() const {
    return clients;
}
