#include "TransactionList.h"

void TransactionList::addTransaction(Transaction* tx) {
    transactions.push_back(tx);
}

const std::vector<Transaction*>& TransactionList::getAllTransactions() const {
    return transactions;
}

Transaction* TransactionList::findTransactionById(const std::string& id) const {
    for (auto* tx : transactions) {
        if (tx->getId() == id) return tx;
    }
    return nullptr;
}
