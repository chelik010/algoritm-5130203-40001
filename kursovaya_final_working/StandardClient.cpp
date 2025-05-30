#include "StandardClient.h"

StandardClient::StandardClient(const std::string& id, const std::string& name, double balance)
    : Client(id, name, balance) {}

double StandardClient::calculateCommission(double amount) const {
    return amount * 0.05;
}

double StandardClient::getMaxTransactionLimit() const {
    return 1000.0;
}

std::string StandardClient::getType() const {
    return "Standard";
}

std::string StandardClient::getBenefits() const {
    return "Базовые функции.";
}
