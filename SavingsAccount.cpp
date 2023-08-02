#include "SavingsAccount.h"

//Display All Members
std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs) {
    os << static_cast<const Account &>(rhs)
       << " savingsAccountType: " << DisplayType(rhs.getSavingsAccountType());
    return os;
}

//Display Savings Type
std::string DisplayType(SavingsAccountType type)
{
    if(SavingsAccountType::METRO==type){
        return "METRO";
    }else if(SavingsAccountType::SPECIAL==type){
        return "SPECIAL";
    }else{
        return "URBAN";
    }
}

//@brief Parameterized Constructor
SavingsAccount::SavingsAccount(long accountNumber, float accountBalance, const float accountMinBalance, SavingsAccountType savingsAccountType)
:Account(accountNumber,accountBalance,accountMinBalance),savingsAccountType(savingsAccountType){
}

//@brief Destructor
SavingsAccount::~SavingsAccount()
{
    std::cout<<"Savings Account Deleted";
}

//Override The Function CalculateInterestAmount 
float SavingsAccount::CalculateInterestAmount()
{
    if(this->getSavingsAccountType()==SavingsAccountType::METRO 
        || this->getSavingsAccountType()==SavingsAccountType::METRO){
        return 0.5f * this->getAccountBalance();
    }
    if(this->getSavingsAccountType()==SavingsAccountType::SPECIAL){
        return 0.7f * this->getAccountBalance();
    }
    return 0.0f;
}

//@Overlod = operator
void SavingsAccount::operator=(SavingsAccount &obj)
{
    this->savingsAccountType=obj.savingsAccountType;
}


