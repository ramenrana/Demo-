#include "Account.h"

//OverLoad << operator
std::ostream &operator<<(std::ostream &os, const Account &rhs) {
    os << "accountNumber: " << rhs.accountNumber
       << " accountBalance: " << rhs.accountBalance
       << " accountMinBalance: " << rhs.accountMinBalance;
    return os;
}

///@brief Parameterized Constructor 
Account::Account(long accountNumber, float accountBalance, const float accountMinBalance)
:accountNumber(accountNumber),accountBalance(accountBalance),accountMinBalance(accountMinBalance){
}

///@brief Account Destructor  
Account::~Account()
{
    std::cout<<"Account Number: "
            <<this->accountNumber
            <<"Deleted";
}

//OverLoad = Operator
void Account::operator=(Account &obj)
{
    this->accountNumber=obj.accountNumber;
    this->accountBalance=obj.accountBalance;
    //this->accountMinBalance=obj.accountMinBalance;
}
