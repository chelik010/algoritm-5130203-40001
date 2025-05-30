#ifndef PLATINUMCLIENT_H
#define PLATINUMCLIENT_H

#include "Client.h"

class PlatinumClient : public Client {
public:
    PlatinumClient(const std::string& id, const std::string& name, double balance);

    double calculateCommission(double amount) const override;
    double getMaxTransactionLimit() const override;
    std::string getType() const override;
    std::string getBenefits() const override;
};

#endif
