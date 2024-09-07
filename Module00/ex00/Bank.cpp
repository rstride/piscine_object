#include "Bank.hpp"

Bank::Bank(double initialFunds) : bankFunds(initialFunds) {}

Account* Bank::findAccount(int accountID) {
    for (auto& acc : accounts) {
        if (acc.getAccountID() == accountID) {
            return &acc;
        }
    }
    return nullptr;
}

void Bank::createAccount(int id, double initialBalance) {
    if (findAccount(id) == nullptr) {
        accounts.push_back(Account(id, initialBalance));
    } else {
        throw std::invalid_argument("Account ID already exists.");
    }
}

void Bank::deposit(int accountID, double amount) {
    Account* acc = findAccount(accountID);
    if (acc != nullptr) {
        double fee = amount * 0.05;
        acc->balance += (amount - fee);
        bankFunds += fee;
    } else {
        throw std::invalid_argument("Account not found.");
    }
}

void Bank::withdraw(int accountID, double amount) {
    Account* acc = findAccount(accountID);
    if (acc != nullptr) {
        if (acc->getBalance() >= amount) {
            acc->balance -= amount;
        } else {
            throw std::invalid_argument("Insufficient funds.");
        }
    } else {
        throw std::invalid_argument("Account not found.");
    }
}

void Bank::giveLoan(int accountID, double loanAmount) {
    Account* acc = findAccount(accountID);
    if (acc != nullptr && bankFunds >= loanAmount) {
        acc->balance += loanAmount;
        bankFunds -= loanAmount;
    } else {
        throw std::invalid_argument("Insufficient bank funds or account not found.");
    }
}