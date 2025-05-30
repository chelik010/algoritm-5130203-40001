#include "Client.h"

Client::Client(const std::string& id, const std::string& name, double balance)
    : Entity(id), name(name) {
    wallet = new Wallet("WALLET_" + id, balance, id);
}

Client::~Client() {
    delete wallet;
}

const std::string& Client::getName() const {
    return name;
}

double Client::getBalance() const {
    return wallet->getBalance();
}

void Client::setBalance(double amount) {
    wallet->setBalance(amount);
}

Wallet* Client::getWallet() const {
    return wallet;
}
#include "Client.h"

Client::Client(const std::string& id, const std::string& name, double balance)
    : Entity(id), name(name) {
    wallet = new Wallet("WALLET_" + id, balance, id);
}

Client::~Client() {
    delete wallet;
}

const std::string& Client::getName() const {
    return name;
}

double Client::getBalance() const {
    return wallet->getBalance();
}

void Client::setBalance(double amount) {
    wallet->setBalance(amount);
}

Wallet* Client::getWallet() const {
    return wallet;
}
