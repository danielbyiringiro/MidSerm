# Banking System in C++

This project implements a simplified banking system in C++ that models the behavior of bank accounts.

## Requirements
- C++ compiler (supporting C++11)
- Standard Template Library (STL)

## Compilation and Execution
1. Compile the program using a C++ compiler. For example:
    ```
    g++ -std=c++11 main.cpp -o banking_system
    ```

2. Run the compiled executable:
    ```
    ./banking_system
    ```

## Functionality
- The program defines a base class `BankAccount` and two derived classes `SavingsAccount` and `CheckingAccount`.
- Each account can deposit, withdraw, and display account information.
- Savings accounts earn interest, and checking accounts have an overdraft limit.
- The program overloads the `+` operator to combine balances of two accounts.
- It uses a vector to store and manage a collection of bank accounts.
- Range-based loops are used to iterate through and display the information of all accounts.

