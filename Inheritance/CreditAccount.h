#pragma once
#include "BaseAccount.h"

class CreditAccount : public BaseAccount {
private:
    int amountSpent;

public:
    // Default constructor
    CreditAccount();

    // Overriding the Withdraw function
    void Withdraw(float amount) override;
};

