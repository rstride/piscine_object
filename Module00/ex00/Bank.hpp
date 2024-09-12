#include <vector>
#include <stdexcept>
#include "Account.hpp"

class Bank {
private:
    std::vector<Account> accounts;
    double bankFunds;

    Account* findAccount(int accountID); // This remains private

public:
    Bank(double initialFunds);
    
    void createAccount(int id, double initialBalance);
    void deposit(int accountID, double amount);
    void withdraw(int accountID, double amount);
    void giveLoan(int accountID, double loanAmount);

    const Account& operator[](int accountID) const; // Overload operator [] for ID-based access

    const double& getBankFunds() const;  // const getter for bank funds (by reference)
};

class Account;