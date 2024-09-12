#include "Bank.hpp"

// Account class implementation
Account::Account(int id, double initialBalance) : accountID(id), balance(initialBalance) {}

int Account::getAccountID() const {
    return accountID;
}

double Account::getBalance() const {  // C++98 does not require return by reference here
    return balance;
}

// Bank class implementation
Bank::Bank(double initialFunds) : bankFunds(initialFunds) {}

Account* Bank::findAccount(int accountID) {
    // Use iterators instead of range-based for loops
    for (std::vector<Account>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getAccountID() == accountID) {
            return &(*it);
        }
    }
    return NULL;  // Use NULL instead of nullptr in C++98
}

void Bank::createAccount(int id, double initialBalance) {
    if (findAccount(id) == NULL) {
        accounts.push_back(Account(id, initialBalance));
    } else {
        throw std::invalid_argument("Account ID already exists.");
    }
}

void Bank::deposit(int accountID, double amount) {
    Account* acc = findAccount(accountID);
    if (acc != NULL) {
        double fee = amount * 0.05;
        acc->getBalance() += (amount - fee);  // Private member access - use a setter if necessary
        bankFunds += fee;
    } else {
        throw std::invalid_argument("Account not found.");
    }
}

void Bank::withdraw(int accountID, double amount) {
    Account* acc = findAccount(accountID);
    if (acc != NULL) {
        if (acc->getBalance() >= amount) {
            acc->setBalance(acc->getBalance() - amount);  // Use a setter method to modify the balance
        } else {
            throw std::invalid_argument("Insufficient funds.");
        }
    } else {
        throw std::invalid_argument("Account not found.");
    }
}

void Bank::giveLoan(int accountID, double loanAmount) {
    Account* acc = findAccount(accountID);
    if (acc != NULL && bankFunds >= loanAmount) {
        acc->getBalance() += loanAmount;  // Private member access - use a setter if necessary
        bankFunds -= loanAmount;
    } else {
        throw std::invalid_argument("Insufficient bank funds or account not found.");
    }
}

const Account& Bank::operator[](int accountID) const {
    for (std::vector<Account>::const_iterator it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getAccountID() == accountID) {
            return *it;
        }
    }
    throw std::invalid_argument("Account not found.");
}

const double& Bank::getBankFunds() const {
    return bankFunds;
}
