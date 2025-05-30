#ifndef GOLDCLIENT_H
#define GOLDCLIENT_H

#include "Client.h"

class GoldClient : public Client {
public:
    GoldClient(const std::string& id, const std::string& name, double balance);

    double calculateCommission(double amount) const override;
    double getMaxTransactionLimit() const override;
    std::string getType() const override;
    std::string getBenefits() const override;
};

#endif
