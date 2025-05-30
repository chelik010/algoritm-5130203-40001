#include "ClientBST.h"
#include "StandardClient.h"
#include "GoldClient.h"
#include "PlatinumClient.h"
#include <fstream>
#include <sstream>

void ClientBST::addClient(Client* client) {
    clients[client->getId()] = client;
}

Client* ClientBST::findClientById(const std::string& id) {
    if (clients.count(id)) return clients[id];
    return nullptr;
}

Wallet* ClientBST::findWalletById(const std::string& walletId) {
    for (auto& [id, client] : clients) {
        if (client->getWallet()->getId() == walletId)
            return client->getWallet();
    }
    return nullptr;
}

Client* ClientBST::findClientByWalletId(const std::string& walletId) {
    for (auto& [id, client] : clients) {
        if (client->getWallet()->getId() == walletId)
            return client;
    }
    return nullptr;
}

const std::map<std::string, Client*>& ClientBST::getAllClients() const {
    return clients;
}

void ClientBST::saveToFile(const std::string& filename) const {
    std::ofstream out(filename);
    for (const auto& [id, client] : clients) {
        out << client->getId() << " "
            << client->getName() << " "
            << client->getType() << " "
            << client->getBalance() << "\n";
    }
    out.close();
}

void ClientBST::loadFromFile(const std::string& filename) {
    std::ifstream in(filename);
    std::string id, name, type;
    double balance;

    while (in >> id >> name >> type >> balance) {
        Client* client = nullptr;
        if (type == "Standard")
            client = new StandardClient(id, name, balance);
        else if (type == "Gold")
            client = new GoldClient(id, name, balance);
        else if (type == "Platinum")
            client = new PlatinumClient(id, name, balance);

        if (client)
            addClient(client);
    }

    in.close();
}
