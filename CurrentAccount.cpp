#include "CurrentAccount.h"

//@brief Parameterized Constructor
CurrentAccount::CurrentAccount(long accountNumber, float accountBalance, const float accountMinBalance, float currentAccountMinimumQuarterBalance, CurrentAccountType currentAccountType)
:Account(accountNumber,accountBalance,accountMinBalance){
    this->currentAccountMinimumQuarterBalance=currentAccountMinimumQuarterBalance;
    this->currentAccountType=currentAccountType;
}

 //@brief Account Destructor 
CurrentAccount::~CurrentAccount()
{
    std::cout<<"Current Account Deleted";
}

//Override The Function CalculateInterestAmount 
float CurrentAccount::CalculateInterestAmount()
{
    if(CurrentAccountType::BASIC==currentAccountType){
        return 0.6f * this->getAccountBalance(); 
    }
    if(CurrentAccountType::PREMIUM==currentAccountType){
        return 0.10f * this->getAccountBalance(); 
    }
    return 0.0f;
}
