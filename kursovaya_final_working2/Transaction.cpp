#include "Transaction.h"

Transaction::Transaction(const std::string& id, const std::string& from, const std::string& to, double amount, double fee)
    : Entity(id), senderWalletId(from), receiverWalletId(to), amount(amount), fee(fee) {}

std::string Transaction::getSenderWalletId() const {
    return senderWalletId;
}

std::string Transaction::getReceiverWalletId() const {
    return receiverWalletId;
}

double Transaction::getAmount() const {
    return amount;
}

double Transaction::getFee() const {
    return fee;
}

std::string Transaction::getId() const {
    return id;
}
