#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "ClientBST.h"
#include "TransactionList.h"
#include "StandardClient.h"
#include "GoldClient.h"
#include "PlatinumClient.h"
#include "Transaction.h"
#include "Wallet.h"

bool isValidTransactionId(const std::string& id) {
    return id.length() >= 3 && std::all_of(id.begin(), id.end(), ::isalnum);
}

bool transactionExists(const TransactionList& txList, const std::string& id) {
    return txList.findTransactionById(id) != nullptr;
}

void loadClients(const std::string& filename, ClientBST& bst) {
    std::ifstream file(filename);
    std::string id, name, type;
    double balance;

    while (file >> id >> name >> type >> balance) {
        Client* client = nullptr;
        if (type == "Standard")
            client = new StandardClient(id, name);
        else if (type == "Gold")
            client = new GoldClient(id, name);
        else if (type == "Platinum")
            client = new PlatinumClient(id, name);
        else
            continue;

        Wallet* wallet = new Wallet("W_" + id, balance, id);
        client->addWallet(wallet);
        bst.addClient(client);
    }
}

void loadTransactions(const std::string& filename, TransactionList& txList) {
    std::ifstream file(filename);
    std::string txId, from, to;
    double amount, fee;

    while (file >> txId >> from >> to >> amount >> fee) {
        txList.addTransaction(new Transaction(txId, from, to, amount, fee));
    }
}

void saveTransactions(const std::string& filename, const TransactionList& txList) {
    std::ofstream file(filename);
    for (auto tx : txList.getAllTransactions()) {
        file << tx->getId() << " " << tx->getSenderWalletId() << " "
             << tx->getReceiverWalletId() << " " << tx->getAmount() << " "
             << tx->getFee() << "\n";
    }
}

int main() {
    ClientBST clients;
    TransactionList txList;

    loadClients("Clients.txt", clients);
    loadTransactions("Blockchain_transactions.txt", txList);

    int choice;
    do {
        std::cout << "\n===== БЛОКЧЕЙН-МЕНЮ =====\n"
                  << "1. Показать клиентов\n"
                  << "2. Показать транзакции\n"
                  << "3. Добавить клиента\n"
                  << "4. Совершить транзакцию\n"
                  << "5. Сохранить данные\n"
                  << "0. Выход\n"
                  << "Выбор: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "\n📋 Список клиентов:\n";
            for (auto& [id, client] : clients.getAllClients()) {
                std::cout << id << " - " << client->getName() << " [" << client->getType()
                          << "] Баланс: " << client->getTotalBalance() << "\n";
            }
        } else if (choice == 2) {
            std::cout << "\n📊 Список транзакций:\n";
            for (auto tx : txList.getAllTransactions()) {
                std::cout << "🔁 ID: " << tx->getId()
                          << " | От: " << tx->getSenderWalletId()
                          << " | Кому: " << tx->getReceiverWalletId()
                          << " | Сумма: " << tx->getAmount()
                          << " | Комиссия: " << tx->getFee() << "\n";
            }
        } else if (choice == 3) {
            std::string id, name, type;
            double balance;

            std::cout << "Введите ID клиента: ";
            std::cin >> id;
            std::cout << "Введите имя: ";
            std::cin >> name;
            std::cout << "Введите тип клиента (Standard, Gold, Platinum): ";
            std::cin >> type;
            std::cout << "Введите стартовый баланс: ";
            std::cin >> balance;

            Client* client = nullptr;
            if (type == "Standard")
                client = new StandardClient(id, name);
            else if (type == "Gold")
                client = new GoldClient(id, name);
            else if (type == "Platinum")
                client = new PlatinumClient(id, name);
            else {
                std::cout << "❌ Неизвестный тип клиента.\n";
                continue;
            }

            Wallet* wallet = new Wallet("W_" + id, balance, id);
            client->addWallet(wallet);
            clients.addClient(client);
            std::cout << "✅ Клиент добавлен.\n";
        } else if (choice == 4) {
            std::string txId, from, to;
            double amount;

            while (true) {
                std::cout << "Введите ID транзакции: ";
                std::cin >> txId;
                if (!isValidTransactionId(txId) || transactionExists(txList, txId)) {
                    std::cout << "❌ Неверный ID транзакции или уже существует.\n";
                } else break;
            }

            Wallet* sender = nullptr;
            while (!sender) {
                std::cout << "ID отправителя (например W_C001): ";
                std::cin >> from;
                sender = clients.findWalletById(from);
                if (!sender)
                    std::cout << "❌ Кошелёк отправителя не найден. Повторите ввод.\n";
            }

            Wallet* receiver = nullptr;
            while (!receiver) {
                std::cout << "ID получателя (например W_C002): ";
                std::cin >> to;
                receiver = clients.findWalletById(to);
                if (!receiver)
                    std::cout << "❌ Кошелёк получателя не найден. Повторите ввод.\n";
            }

            Client* senderClient = clients.findClientByWalletId(from);
            double maxLimit = senderClient->getMaxTransactionLimit();
            double fee = 0.0;

            while (true) {
                std::cout << "Сумма перевода: ";
                std::cin >> amount;
                fee = senderClient->calculateCommission(amount);

                if (amount <= 0) {
                    std::cout << "❌ Сумма должна быть положительной.\n";
                } else if (amount > maxLimit) {
                    std::cout << "❌ Превышен лимит (" << maxLimit << ").\n";
                } else if (sender->getBalance() < amount + fee) {
                    std::cout << "❌ Недостаточно средств у отправителя (учитывая комиссию " << fee << ").\n";
                } else break;
            }

            sender->decreaseBalance(amount + fee);
            receiver->increaseBalance(amount);
            txList.addTransaction(new Transaction(txId, from, to, amount, fee));
            std::cout << "✅ Транзакция успешно проведена!\n";
        } else if (choice == 5) {
            saveTransactions("Blockchain_transactions.txt", txList);
            std::cout << "✅ Данные сохранены.\n";
        }

    } while (choice != 0);

    return 0;
}
