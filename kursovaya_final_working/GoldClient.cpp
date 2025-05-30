#include "GoldClient.h"

GoldClient::GoldClient(const std::string& id, const std::string& name, double balance)
    : Client(id, name, balance) {}

double GoldClient::calculateCommission(double amount) const {
    return amount * 0.01;
}

double GoldClient::getMaxTransactionLimit() const {
    return 10000.0;
}

std::string GoldClient::getType() const {
    return "Gold";
}

std::string GoldClient::getBenefits() const {
    return "Пониженная комиссия и повышенный лимит.";
}
