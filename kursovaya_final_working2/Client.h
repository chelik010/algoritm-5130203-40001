#ifndef CLIENT_H
#define CLIENT_H

#include "Entity.h"
#include "Wallet.h"
#include <vector>
#include <string>

class Client : public Entity {
protected:
    std::string name;
    std::vector<Wallet*> wallets;

public:
    Client(const std::string& id, const std::string& name) : Entity(id), name(name) {}
    virtual ~Client() = default;

    const std::string& getName() const { return name; }
    void addWallet(Wallet* wallet) { wallets.push_back(wallet); }
    const std::vector<Wallet*>& getWallets() const { return wallets; }

    double getTotalBalance() const {
        double total = 0.0;
        for (const auto& wallet : wallets)
            total += wallet->getBalance();
        return total;
    }

    virtual double calculateCommission(double amount) const = 0;
    virtual double getMaxTransactionLimit() const = 0;
    virtual std::string getBenefits() const = 0;
    virtual std::string getType() const = 0;
};

#endif // CLIENT_H
