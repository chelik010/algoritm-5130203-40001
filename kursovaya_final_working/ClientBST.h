#ifndef CLIENTBST_H
#define CLIENTBST_H

#include "Client.h"
#include <map>
#include <string>

class ClientBST {
private:
    std::map<std::string, Client*> clients;

public:
    void addClient(Client* client);
    Client* findClientById(const std::string& id);
    Client* findClientByWalletId(const std::string& walletId);
    Wallet* findWalletById(const std::string& walletId);
    const std::map<std::string, Client*>& getAllClients() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif
