#ifndef TRANSACTION_LIST_H
#define TRANSACTION_LIST_H

#include <vector>
#include "Transaction.h"

class TransactionList {
private:
    std::vector<Transaction*> transactions;

public:
    void addTransaction(Transaction* tx);
    const std::vector<Transaction*>& getAllTransactions() const;
    Transaction* findTransactionById(const std::string& id) const;
};

#endif
