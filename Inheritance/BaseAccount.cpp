#include "BaseAccount.h"

void BaseAccount::Withdraw(float amount) {
    balance -= amount;
    numWithdrawals++;
}

void BaseAccount::Deposit(float amount) {
    balance += amount;
}

float BaseAccount::GetBalance() const {
    return balance;
}
