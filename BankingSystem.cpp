#include <iostream>
using namespace std;
// Encapsulation with real world example
class BankAccount {
private:
    // Encapsulated data (hidden from outside)
    double balance;

public:
    // Constructor to initialize the balance
    BankAccount(double initialBalance) {
        if (initialBalance >= 0)
            balance = initialBalance;
        else
            balance = 0;
    }


    // Method to deposit money
    void deposit(double amount) {
        if (amount > 0)
            balance += amount;
        else
            cout << "Invalid deposit amount!" << endl;
    }

    // Method to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance)
            balance -= amount;
        else
            cout << "Invalid or insufficient funds!" << endl;
    }

    // Method to check the balance
    double getBalance()const {
        // const tells the compiler that getBalance() will not alter any member variables of the class.

        return balance;
    }
};

int main() {
    BankAccount myAccount(1000); // Initial balance of $1000
    

    // Interacting with the account through methods
    myAccount.deposit(500);      // Deposits $500
    myAccount.withdraw(200);     // Withdraws $200

    // Check balance
    cout << "Current balance: $" << myAccount.getBalance() << endl;

    return 0;
}
