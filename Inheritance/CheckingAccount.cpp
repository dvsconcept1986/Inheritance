#include <iostream>
#include "CheckingAccount.h"

void CheckingAccount::Withdraw(float amount) {
    // Call the base class Withdraw function to decrease balance
    BaseAccount::Withdraw(amount);

    // If more than 10 withdrawals have been made, apply $5 fee
    if (numWithdrawals > 10) {
        std::cout << "A $5 fee has been applied for exceeding 10 withdrawals." << std::endl;
        balance -= 5.0f; // Apply the fee
    }
}
