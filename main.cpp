#include <iostream>
#include <vector>
using namespace std;

/**
	Fullname: Daniel Byiringiro
	Student ID: 78512025
**/

// Base class representing a bank account
class BankAccount {
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructors
    BankAccount() : accountNumber(""), accountHolderName(""), balance(0) {}
    BankAccount(string accNo, string accName, double bal) : accountNumber(accNo), accountHolderName(accName), balance(bal) {}
    BankAccount(const BankAccount& other) : accountNumber(other.accountNumber), accountHolderName(other.accountHolderName), balance(other.balance) {}

    // Virtual functions for polymorphism
    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { balance -= amount; }
    virtual void display() const {
        cout << "Account Number: " << accountNumber
             << "  Account Holder Name: " << accountHolderName
             << "  Balance: " << balance << endl;
    }

    // Overloading '+' operator to combine balances of two accounts
    BankAccount operator+(const BankAccount& other) {
        return BankAccount("", "", balance + other.balance);
    }
};

// Derived class for savings account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNo, string accName, double bal, double intRate)
        : BankAccount(accNo, accName, bal), interestRate(intRate) {}

    // Function to add interest to savings account
    void addInterest() {
        balance += (balance * interestRate);
    }

    // Override display function to show interest rate
    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << endl;
    }
};

// Derived class for checking account
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNo, string accName, double bal, double overDraft)
        : BankAccount(accNo, accName, bal), overdraftLimit(overDraft) {}

    // Override withdraw function to consider overdraft limit
    void withdraw(double amount) override {
        if (balance > overdraftLimit) {
            BankAccount::withdraw(amount);
        } else {
            cout << "You have reached your overdraft limit" << endl;
        }
    }

    // Override display function to show overdraft limit
    void display() const override {
        BankAccount::display();
        cout << "Overdraft Limit: " << overdraftLimit << endl;
    }
};

int main() {
    // Create instances of bank accounts
    BankAccount b1;
    BankAccount b2("78512025", "Daniel Byiringiro", 900);
    BankAccount b3(b2);

    // Display initial account information
    cout << "Displaying initial account information" << endl;
    cout << endl;
    
    b1.display();
    b2.display();
    b3.display();
    
    cout << endl;
    

    // Deposit, withdraw, and display updated account information
    b1.deposit(500);
    b2.withdraw(500);
    
    cout << "Displaying account information after deposit and withdrawal" << endl;
	
	cout << endl;
	
    b1.display();
    b2.display();
    b3.display();
	
	cout << endl;
	
    // Create and manipulate savings account
    cout << "Displaying initial account information for savings account" << endl;
    cout << endl;
    SavingsAccount s1("1199", "Xerxes", 1000, 0.1);
    s1.display();
    cout << endl;
    
    cout << "Displaying account information for savings account after adding interest" << endl;
    cout << endl;
    s1.addInterest();
    s1.display();
    cout << endl;

    // Create and manipulate checking account
    cout << "Displaying initial account information for checking account" << endl;
    cout << endl;
    
    CheckingAccount c1("2020", "Daniel", 1200, 600);
    c1.display();
    cout << endl;
    
    cout << "Displaying account information for checking account after withdrawal" << endl;
    cout << endl;
    c1.withdraw(700);
    c1.display();
    c1.withdraw(200);
    c1.display();
    cout << endl;

    // Combine balances of two accounts using operator overloading
    cout << "Displaying account information after using the + operator to merge two accounts" << endl;
    cout << endl;
    
    BankAccount b4 = b3 + b2;
    b4.display();
    
    cout << endl;

    // Create a vector to store bank accounts and add accounts to it
    vector<BankAccount> accounts;
    accounts.push_back(b1);
    accounts.push_back(b2);
    accounts.push_back(b3);
    accounts.push_back(s1);
    accounts.push_back(c1);
    accounts.push_back(b4);

    // Display information of all accounts using range-based loop
    cout << "Displaying all accounts information using a range based for loop" << endl;
    cout << endl;
    for (auto& acc : accounts) {
        acc.display();
    }

    return 0;
}

