#ifndef FINANCIALTRANSACTION_H
#define FINANCIALTRANSACTION_H

class FinancialTransaction {
protected:
    double amount;

public:
    FinancialTransaction(double amt = 0.0);
    void setAmount(double amt);
    double getAmount() const;
    virtual void process() = 0;
    virtual void print_transaction() const;
    virtual ~FinancialTransaction();
};

class Deposit : public FinancialTransaction {
private:
    double balance;

public:
    Deposit(double amt = 0.0, double bal = 0.0);
    void process() override;
    double getBalance() const;
    void print_transaction() const override;
};

class Credit : public FinancialTransaction {
private:
    double interest_rate;
    char type;
    int months;
    double total_interest;

public:
    Credit(double amt = 0.0, double rate = 0.0, char t = 'A', int m = 0);
    void set_interest_rate(double rate);
    void set_type(char t);
    void set_months(int m);
    double get_months() const;
    void process() override;
    void print_transaction() const override;
};

#endif // FINANCIALTRANSACTION_H
