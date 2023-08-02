#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include <iostream>
#include "Account.h"
#include "CurrentAccountType.h"

class CurrentAccount: public Account
{
private:
    float currentAccountMinimumQuarterBalance;
    CurrentAccountType currentAccountType;
public:

    //@brief Default Constructor
    CurrentAccount()=default;

    //@brief Default Copy Constructor
    CurrentAccount(CurrentAccount &obj)=default;

    //@brief Move Constructor Deleted
    CurrentAccount(CurrentAccount &&obj)=delete;

    //@brief Parameterized Constructor
    CurrentAccount(long accountNumber,
        float accountBalance,
        const float accountMinBalance,
        float currentAccountMinimumQuarterBalance, CurrentAccountType currentAccountType);

    //@brief Account Destructor 
    ~CurrentAccount();


    //Override The Function CalculateInterestAmount 
    float CalculateInterestAmount () override;

    //Getter Setter Functions
    float getCurrentAccountMinimumQuarterBalance() const { return currentAccountMinimumQuarterBalance; }
    void setCurrentAccountMinimumQuarterBalance(float currentAccountMinimumQuarterBalance_) { currentAccountMinimumQuarterBalance = currentAccountMinimumQuarterBalance_; }

    CurrentAccountType getCurrentAccountType() const { return currentAccountType; }
    void setCurrentAccountType(const CurrentAccountType &currentAccountType_) { currentAccountType = currentAccountType_; }

};


#endif // CURRENTACCOUNT_H
