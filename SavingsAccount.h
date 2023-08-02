#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include "Account.h"
#include "SavingsAccountType.h"

class SavingsAccount:public Account
{
private:
    SavingsAccountType savingsAccountType;

public:
    //@brief Default Constructor
    SavingsAccount()=default;
    
    //@brief Default Copy Constructor
    SavingsAccount(SavingsAccount &obj)=default;
    
    //@brief Move Constructor Deleted
    SavingsAccount(SavingsAccount &&obj)=delete;
    
    //@brief Parameterized Constructor
    SavingsAccount(long accountNumber,
        float accountBalance,
        const float accountMinBalance,
        SavingsAccountType savingsAccountType);

    //@brief Destructor 
    ~SavingsAccount();

    //Override The Function CalculateInterestAmount 
    float CalculateInterestAmount () override;

    //@Overlod = operator
    void operator=(SavingsAccount &obj);

    //Getter Setter Methods
    SavingsAccountType getSavingsAccountType() const { return savingsAccountType; }
    void setSavingsAccountType(const SavingsAccountType &savingsAccountType_) { savingsAccountType = savingsAccountType_; }

    //Over load << operator for display the data members
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs);

    
};
//Display Enum
std::string DisplayType(SavingsAccountType type);
#endif // SAVINGSACCOUNT_H
