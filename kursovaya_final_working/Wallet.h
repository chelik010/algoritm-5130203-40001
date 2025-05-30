#ifndef WALLET_H
#define WALLET_H

#include "Entity.h"
#include <string>

class Wallet : public Entity {
private:
    double balance;
    std::string ownerId;

public:
    Wallet(const std::string& id, double balance, const std::string& ownerId);

    double getBalance() const;
    void setBalance(double amount);
    void increaseBalance(double amount);
    void decreaseBalance(double amount);
    const std::string& getOwnerId() const;
};

#endif
