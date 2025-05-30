#ifndef CLIENT_H
#define CLIENT_H

#include "Entity.h"
#include "Wallet.h"
#include <vector>

class Client : public Entity {
protected:
    std::string name;
    Wallet* wallet;

public:
    Client(const std::string& id, const std::string& name, double balance);
    virtual ~Client();

    const std::string& getName() const;
    double getBalance() const;
    void setBalance(double amount);
    Wallet* getWallet() const;

    virtual double calculateCommission(double amount) const = 0;
    virtual double getMaxTransactionLimit() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getBenefits() const = 0;
};

#endif
