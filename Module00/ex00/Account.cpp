#include "Account.hpp"

Account::Account(int id, double initialBalance) : accountID(id), balance(initialBalance) {}

int Account::getAccountID() const {
    return accountID;
}

double Account::getBalance() const {
    return balance;
}