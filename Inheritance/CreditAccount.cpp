#include <iostream>
#include "CreditAccount.h"

CreditAccount::CreditAccount() : amountSpent(0) {}

void CreditAccount::Withdraw(float amount) {
    // Check if withdrawing the given amount would exceed the spending limit
    if (amountSpent + amount > 40) {
        // Apply the fee
        std::cout << "A $5000 fee has been applied for exceeding the spending limit." << std::endl;
        balance -= 5000;
    }

    // Call the base class Withdraw function to decrease balance
    BaseAccount::Withdraw(amount);

    // Update the amount spent
    amountSpent += amount;
}