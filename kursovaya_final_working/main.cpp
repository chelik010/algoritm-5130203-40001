#include <iostream>
#include <fstream>
#include <sstream>
#include "ClientBST.h"
#include "TransactionList.h"
#include "StandardClient.h"
#include "GoldClient.h"
#include "PlatinumClient.h"

int main() {
    ClientBST clients;
    TransactionList txList;

    std::string clientFile = "Clients.txt";
    std::string txFile = "Blockchain_transactions.txt";

    clients.loadFromFile(clientFile);
    txList.loadFromFile(txFile);

    while (true) {
        std::cout << "\n1. Создать клиента\n2. Провести транзакцию\n3. Показать всех клиентов\n4. Показать все транзакции\n5. Выход\n> ";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string id, name, type;
            double balance;
            std::cout << "ID клиента: "; std::cin >> id;
            std::cout << "Имя клиента: "; std::cin >> name;
            std::cout << "Тип (Standard/Gold/Platinum): "; std::cin >> type;
            std::cout << "Начальный баланс: "; std::cin >> balance;

            Client* client = nullptr;
            if (type == "Standard")
                client = new StandardClient(id, name, balance);
            else if (type == "Gold")
                client = new GoldClient(id, name, balance);
            else if (type == "Platinum")
                client = new PlatinumClient(id, name, balance);
            else {
                std::cout << "❌ Неверный тип клиента.\n";
                continue;
            }

            clients.addClient(client);
            clients.saveToFile(clientFile);
            std::cout << "✅ Клиент создан.\n";
        }

        else if (choice == 2) {
            std::string txId, fromId, toId;
            double amount;
            std::cout << "ID транзакции: "; std::cin >> txId;
            std::cout << "Отправитель (ID): "; std::cin >> fromId;
            std::cout << "Получатель (ID): "; std::cin >> toId;
            std::cout << "Сумма: "; std::cin >> amount;

            Client* sender = clients.findClientByWalletId(fromId);
            Client* receiver = clients.findClientByWalletId(toId);

            if (!sender || !receiver) {
                std::cout << "❌ Клиент не найден.\n";
                continue;
            }

            double fee = sender->calculateCommission(amount);
            double total = amount + fee;

            if (sender->getBalance() < total) {
                std::cout << "❌ Недостаточно средств. Требуется " << total << "\n";
                continue;
            }

            if (amount > sender->getMaxTransactionLimit()) {
                std::cout << "❌ Превышен лимит транзакции.\n";
                continue;
            }

            sender->setBalance(sender->getBalance() - total);
            receiver->setBalance(receiver->getBalance() + amount);

            Transaction* tx = new Transaction(txId, fromId, toId, amount, fee);
            txList.addTransaction(tx);

            clients.saveToFile(clientFile);
            txList.saveToFile(txFile);

            std::cout << "✅ Транзакция завершена.\n";
        }

        else if (choice == 3) {
            for (const auto& [id, client] : clients.getAllClients()) {
                std::cout << "[" << id << "] " << client->getName()
                          << " (" << client->getType() << ") — Баланс: "
                          << client->getBalance() << "\n";
            }
        }

        else if (choice == 4) {
            txList.displayAll();
        }

        else if (choice == 5) {
            break;
        }

        else {
            std::cout << "❌ Неизвестная команда\n";
        }
    }

    return 0;
}
