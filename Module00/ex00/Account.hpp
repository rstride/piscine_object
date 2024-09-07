#pragma once

class Account {
    private:
        int accountID;
        double balance;

    public:
    Account(int accountID, double initialBalance);

    int getAccountID() const;
    double getBalance() const;
};

