#include "Wallet.h"

Wallet::Wallet(const std::string& id, const std::string& ownerId, double balance)
    : Entity(id), balance(balance), ownerId(ownerId) {}


double Wallet::getBalance() const {
    return balance;
}

void Wallet::deposit(double amount) {
    balance += amount;
}

void Wallet::withdraw(double amount) {
    balance -= amount;
}

void Wallet::increaseBalance(double amount) {
    balance += amount;
}

void Wallet::decreaseBalance(double amount) {
    balance -= amount;
}

std::string Wallet::getId() const {
    return id;
}
