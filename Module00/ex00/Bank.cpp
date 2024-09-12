#include "Bank.hpp"

Account::Account(int id, double initialBalance) : accountID(id), balance(initialBalance) {}

int Account::getAccountID() const {
    return accountID;
}

double Account::getBalance() const {  
    return balance;
}

Bank::Bank(double initialFunds) : bankFunds(initialFunds) {}

Account* Bank::findAccount(int accountID) {
    for (std::vector<Account>::iterator it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->getAccountID() == accountID) {
            return &(*it);
        }
    }
    return NULL;  
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
        acc->getBalance() += (amount - fee);  
        bankFunds += fee;
    } else {
        throw std::invalid_argument("Account not found.");
    }
}

void Bank::withdraw(int accountID, double amount) {
    Account* acc = findAccount(accountID);
    if (acc != NULL) {
        if (acc->getBalance() >= amount) {
            acc->setBalance(acc->getBalance() - amount);  
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
        acc->getBalance() += loanAmount;  
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
