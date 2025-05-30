#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "Entity.h"

class Transaction : public Entity {
private:
    std::string senderWalletId;
    std::string receiverWalletId;
    double amount;
    double fee;

public:
    Transaction(const std::string& id, const std::string& from, const std::string& to, double amount, double fee);

    std::string getSenderWalletId() const;
    std::string getReceiverWalletId() const;

    double getAmount() const;
    double getFee() const;

    std::string getId() const override;
};

#endif
