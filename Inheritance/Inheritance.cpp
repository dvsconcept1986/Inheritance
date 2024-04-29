//
// Lab 4 Inheritance for Systems Programming
//

#include <iostream>
#include <fstream>
#include <crtdbg.h>
#include "CheckingAccount.h"
#include "SavingsAccount.h"
#include "CreditAccount.h"

// Change this number to the line number the Output window shows you
// to follow a memory leak. Put -1 to disable.
#define MEMORY_LEAK_LINE -1

void deposit(BaseAccount* account, float amount) {
    account->Deposit(amount);
    std::cout << "$" << amount << " deposited to account!" << std::endl;
}

void withdraw(BaseAccount* account, float amount) {
    account->Withdraw(amount);
    std::cout << "$" << amount << " withdrawn from account!" << std::endl;
}

int main() {
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    _CrtSetBreakAlloc(MEMORY_LEAK_LINE);

    // Create instances of each derived class on the heap
    CheckingAccount* checking = new CheckingAccount();
    SavingsAccount* savings = new SavingsAccount();
    CreditAccount* credit = new CreditAccount();

    // Open the binary file for reading
    std::ifstream inFile("balances.bin", std::ios::binary);
    if (inFile.is_open()) {
        // Read balances from the file and deposit them into account variables
        float balances[3];
        inFile.read(reinterpret_cast<char*>(&balances), sizeof(balances));
        checking->Deposit(balances[0]);
        savings->Deposit(balances[1]);
        credit->Deposit(balances[2]);
        std::cout << "Balances loaded from file 'balances.bin' successfully!" << std::endl;
    }
    else {
        std::cerr << "Unable to open file 'balances.bin' for reading!" << std::endl;
        // Initialize balances if file does not exist or cannot be opened
        checking->Deposit(1000.0f);
        savings->Deposit(500.0f);
        credit->Deposit(2000.0f);
    }

    // Menu loop
    int choice;
    float amount;
    do {
        std::cout << "Choose an option:\n"
            "1. Deposit\n"
            "2. Withdraw\n"
            "3. Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter amount to deposit: ";
            std::cin >> amount;
            deposit(checking, amount);
            deposit(savings, amount);
            deposit(credit, amount);
            break;
        case 2:
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;
            withdraw(checking, amount);
            withdraw(savings, amount);
            withdraw(credit, amount);
            break;
        case 3:
            break;
        default:
            std::cout << "Invalid choice! Please try again.\n";
        }

        // Print balances
        std::cout << "Checking Account Balance: $" << checking->GetBalance() << std::endl;
        std::cout << "Savings Account Balance: $" << savings->GetBalance() << std::endl;
        std::cout << "Credit Account Balance: $" << credit->GetBalance() << std::endl;

    } while (choice != 3);

    // Write balances to a binary file
    std::ofstream outFile("balances.bin", std::ios::binary);
    if (outFile.is_open()) {
        float balances[] = { checking->GetBalance(), savings->GetBalance(), credit->GetBalance() };
        outFile.write(reinterpret_cast<char*>(&balances), sizeof(balances));
        outFile.close();
        std::cout << "Balances written to file 'balances.bin' successfully!" << std::endl;
    }
    else {
        std::cerr << "Unable to open file 'balances.bin' for writing!" << std::endl;
    }

    // Clean up memory
    delete checking;
    delete savings;
    delete credit;

    return 0;
}
