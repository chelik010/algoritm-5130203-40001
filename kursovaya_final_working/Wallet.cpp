#include "Wallet.h"

Wallet::Wallet(const std::string& id, double balance, const std::string& ownerId)
    : Entity(id), balance(balance), ownerId(ownerId) {}

double Wallet::getBalance() const {
    return balance;
}

void Wallet::setBalance(double amount) {
    balance = amount;
}

void Wallet::increaseBalance(double amount) {
    balance += amount;
}

void Wallet::decreaseBalance(double amount) {
    balance -= amount;
}

const std::string& Wallet::getOwnerId() const {
    return ownerId;
}
