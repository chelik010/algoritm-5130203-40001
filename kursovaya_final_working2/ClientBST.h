#ifndef CLIENT_BST_H
#define CLIENT_BST_H

#include <map>
#include <string>
#include "Client.h"
#include "Wallet.h"

class ClientBST {
private:
    std::map<std::string, Client*> clients;

public:
    void addClient(Client* client);
    Client* findClientById(const std::string& id);
    Wallet* findWalletById(const std::string& walletId);
    Client* findClientByWalletId(const std::string& walletId);

    const std::map<std::string, Client*>& getAllClients() const;
};

#endif
