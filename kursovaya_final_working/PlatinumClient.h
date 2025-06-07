#ifndef PLATINUMCLIENT_H
#define PLATINUMCLIENT_H

#include "Client.h"

class PlatinumClient : public Client {
public:
    PlatinumClient(const std::string& id, const std::string& name)
        : Client(id, name) {}

    double calculateCommission(double amount) const override {
        return amount * 0.005;
    }

    double getMaxTransactionLimit() const override {
        return 10000.0;
    }

    std::string getBenefits() const override {
        return "Platinum benefits";
    }

    std::string getType() const override {
        return "Platinum";
    }
};

#endif
