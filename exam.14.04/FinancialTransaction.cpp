#include <iostream>
#include <iomanip>
#include <cmath>
#include "FinancialTransaction.h"

using namespace std;

FinancialTransaction::FinancialTransaction(double amt) : amount(amt) {}

void FinancialTransaction::setAmount(double amt) {
    amount = amt;
}

double FinancialTransaction::getAmount() const {
    return amount;
}

void FinancialTransaction::print_transaction() const {
    cout << "Сумма транзакции: $" << fixed << setprecision(2) << amount << endl;
}

FinancialTransaction::~FinancialTransaction() {}

Deposit::Deposit(double amt, double bal) : FinancialTransaction(amt), balance(bal) {}

void Deposit::process() {
    balance += amount;
}

double Deposit::getBalance() const {
    return balance;
}

void Deposit::print_transaction() const {
    cout << "Транзакция по депозиту" << endl;
    FinancialTransaction::print_transaction();
    cout << "Новый баланс: $" << fixed << setprecision(2) << balance << endl;
}

Credit::Credit(double amt, double rate, char t, int m)
    : FinancialTransaction(amt), interest_rate(rate), type(t), months(m), total_interest(0.0) {}

void Credit::set_interest_rate(double rate) {
    interest_rate = rate;
}

void Credit::set_type(char t) {
    type = t;
}

void Credit::set_months(int m) {
    months = m;
}

double Credit::get_months() const {
    return months;
}

void Credit::process() {
    if (type == 'A') {
        total_interest = amount + (amount * interest_rate * months) / 100.0;
    } else if (type == 'B') {
        total_interest = amount * pow(1 + interest_rate / 100.0, months);
    }
}

void Credit::print_transaction() const {
    cout << "Транзакция по кредиту" << endl;
    FinancialTransaction::print_transaction();
    cout << "Тип: " << type << endl;
    cout << "Процентная ставка: " << interest_rate << "%" << endl;
    cout << "Месяцев: " << months << endl;
    cout << "Общая сумма для оплаты: $" << fixed << setprecision(2) << total_interest << endl;
}