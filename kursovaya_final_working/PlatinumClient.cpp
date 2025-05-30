#include "PlatinumClient.h"

PlatinumClient::PlatinumClient(const std::string& id, const std::string& name, double balance)
    : Client(id, name, balance) {}

double PlatinumClient::calculateCommission(double amount) const {
    return amount * 0.02;
}

double PlatinumClient::getMaxTransactionLimit() const {
    return 50000.0;
}

std::string PlatinumClient::getType() const {
    return "Platinum";
}

std::string PlatinumClient::getBenefits() const {
    return "Эксклюзивные привилегии и средняя комиссия.";
}
