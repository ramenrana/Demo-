#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

class Account
{
private:
    long accountNumber;
    float accountBalance;
    const float accountMinBalance;
public:
    //@brief Default Constructor
    Account()=default;
    
    //@brief Default Copy Constructor
    Account(Account &obj)=delete;

    //@brief Move Constructor Deleted
    Account(Account&& obj)=delete;

    //@brief Parameterized Constructor 
    Account(long accountNumber,
        float accountBalance,
        const float accountMinBalance
        );

    //@brief Account Destructor  
    ~Account();
    
    //Getter Setter Functions
    long getAccountNumber() const { return accountNumber; }
    void setAccountNumber(long accountNumber_) { accountNumber = accountNumber_; }

    float getAccountBalance() const { return accountBalance; }
    void setAccountBalance(float accountBalance_) { accountBalance = accountBalance_; }

    float getAccountMinBalance() const { return accountMinBalance; }
    
    //Abstract Function CalculateInterestAmount 
    virtual float CalculateInterestAmount()=0;

    //OverLoad = Operator
    void operator=(Account &obj);

    //OverLoad << operator
    friend std::ostream &operator<<(std::ostream &os, const Account &rhs);
};

#endif // ACCOUNT_H
