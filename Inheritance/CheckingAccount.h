#pragma once
#include "BaseAccount.h"
class CheckingAccount : public BaseAccount {
public:
    // Default constructor
    CheckingAccount() {}

    // Overriding the Withdraw function
    void Withdraw(float amount) override;
};

