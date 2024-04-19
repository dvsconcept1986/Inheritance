#pragma once
class BaseAccount
{
protected:
    float balance;
    int numWithdrawals;

public:
    // Default constructor
    BaseAccount() : balance(0.0f), numWithdrawals(0) {}

    // Virtual destructor
    virtual ~BaseAccount() {}

    // Virtual function for withdrawing from the account
    virtual void Withdraw(float amount);

    // Function for depositing into the account
    void Deposit(float amount);

    // Function to get the current balance
    float GetBalance() const;

};

