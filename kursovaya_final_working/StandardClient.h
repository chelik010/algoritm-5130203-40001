#ifndef STANDARDCLIENT_H
#define STANDARDCLIENT_H

#include "Client.h"

class StandardClient : public Client {
public:
    StandardClient(const std::string& id, const std::string& name)
        : Client(id, name) {}

    double calculateCommission(double amount) const override {
        return amount * 0.05;
    }

    double getMaxTransactionLimit() const override {
        return 1000.0;
    }

    std::string getBenefits() const override {
        return "Standard benefits";
    }

    std::string getType() const override {
        return "Standard";
    }
};

#endif
