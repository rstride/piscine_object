#include <iostream>
#include "Bank.hpp"
#include "Account.hpp"

int main() {
    // Create a bank with an initial fund of 10000
    Bank bank(10000);

    // Create some accounts
    try {
        bank.createAccount(1, 1000);
        bank.createAccount(2, 500);
        bank.createAccount(3, 1200);
    } catch (const std::exception& e) {
        std::cerr << "Error creating account: " << e.what() << std::endl;
    }

    // Display balances for all accounts
    try {
        std::cout << "Account 1 balance: " << bank.findAccount(1)->getBalance() << std::endl;
        std::cout << "Account 2 balance: " << bank.findAccount(2)->getBalance() << std::endl;
        std::cout << "Account 3 balance: " << bank.findAccount(3)->getBalance() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error displaying balance: " << e.what() << std::endl;
    }

    // Deposit money into account 1
    try {
        std::cout << "\nDepositing 200 into Account 1...\n";
        bank.deposit(1, 200);
        std::cout << "New Account 1 balance: " << bank.findAccount(1)->getBalance() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error depositing money: " << e.what() << std::endl;
    }

    // Withdraw money from account 2
    try {
        std::cout << "\nWithdrawing 100 from Account 2...\n";
        bank.withdraw(2, 100);
        std::cout << "New Account 2 balance: " << bank.findAccount(2)->getBalance() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error withdrawing money: " << e.what() << std::endl;
    }

    // Give a loan to account 3
    try {
        std::cout << "\nGiving a loan of 300 to Account 3...\n";
        bank.giveLoan(3, 300);
        std::cout << "New Account 3 balance: " << bank.findAccount(3)->getBalance() << std::endl;
        std::cout << "Remaining bank funds: " << bank.getBankFunds() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error giving loan: " << e.what() << std::endl;
    }

    return 0;
}
