#ifndef GOLDCLIENT_H
#define GOLDCLIENT_H

#include "Client.h"

class GoldClient : public Client {
public:
    GoldClient(const std::string& id, const std::string& name)
        : Client(id, name) {}

    double calculateCommission(double amount) const override {
        return amount * 0.01;
    }

    double getMaxTransactionLimit() const override {
        return 5000.0;
    }

    std::string getBenefits() const override {
        return "Gold benefits";
    }

    std::string getType() const override {
        return "Gold";
    }
};

#endif
