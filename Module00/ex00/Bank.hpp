#pragma once

#include <vector>
#include "Account.hpp"

class Account;

class Bank {
    private:
        std::vector<Account> accounts;
        double bankFunds;

        Account* findAccount(int accountID);

    public:
        Bank(double initialFunds);

        void createAccount(int accountID, double initialBalance);
        void deposit(int accountID, double amount);
        void withdraw(int accountID, double amount);
        void giveLoan(int accountID, double loanAmount);
};
