#ifndef STANDARDCLIENT_H
#define STANDARDCLIENT_H

#include "Client.h"

class StandardClient : public Client {
public:
    StandardClient(const std::string& id, const std::string& name, double balance);

    double calculateCommission(double amount) const override;
    double getMaxTransactionLimit() const override;
    std::string getType() const override;
    std::string getBenefits() const override;
};

#endif
