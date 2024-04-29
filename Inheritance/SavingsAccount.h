#pragma once
#include "BaseAccount.h"
class SavingsAccount : public BaseAccount
{
public:
    // Default constructor
    SavingsAccount();

    // Overriding the Withdraw function
    void Withdraw(float amount) override;
};

