#include <iostream>
#include "FinancialTransaction.h"

using namespace std;

int main() {
    double amount, rate;
    int months;
    char type;

    cout << "Введите сумму депозита: ";
    cin >> amount;
    cout << "Введите начальный баланс: ";
    double balance;
    cin >> balance;
    Deposit dep(amount, balance);
    dep.process();
    dep.print_transaction();

    cout << "------------------------" << endl;

    cout << "Введите сумму кредита: ";
    cin >> amount;
    cout << "Введите процентную ставку: ";
    cin >> rate;
    cout << "Введите тип кредита (A или B): ";
    cin >> type;
    cout << "Введите количество месяцев: ";
    cin >> months;
    Credit cred(amount, rate, type, months);
    cred.process();
    cred.print_transaction();

    return 0;
}
