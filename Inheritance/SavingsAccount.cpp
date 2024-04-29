#include <iostream>
#include "SavingsAccount.h"

SavingsAccount::SavingsAccount() {}

void SavingsAccount::Withdraw(float amount) {
    // If more than 3 withdrawals have been made, inform the user and return
    if (numWithdrawals >= 3) {
        std::cout << "Sorry, no more withdrawals allowed for this savings account." << std::endl;
        return;
    }

    // Call the base class Withdraw function to decrease balance
    BaseAccount::Withdraw(amount);
}



