#ifndef WALLET_H
#define WALLET_H

#include "Entity.h"

class Wallet : public Entity {
    double balance;
    std::string ownerId;

public:
    Wallet(const std::string& id, double balance, const std::string& ownerId);

    double getBalance() const;
    void deposit(double amount);
    void withdraw(double amount);

    void increaseBalance(double amount);
    void decreaseBalance(double amount);

    std::string getId() const override;
};

#endif
