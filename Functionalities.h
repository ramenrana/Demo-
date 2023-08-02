#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "CurrentAccountType.h"
#include "SavingsAccountType.h"
#include <memory>
#include <list>

using Pointer = std::unique_ptr<Account>;
using Container = std::list<Pointer>;

//Check Container is Empty or not
bool Check(Container &data);

//Create Objects of Type Account
void CreateObject(Container &data);

//Find The Average of all Account Balance 
float AverageOFAllBalance(Container &data);

//Find The Average of all Savings Account Balance
float AverageOfSavingsAccBalance(Container &data);

//Find Average Minimum Balance for all Current Account;
float AverageMinOfCurrentAcc(Container &data);

//Total Interest of All Account 
float TotalInterest(Container &data);

//Find Account With Minimum Account Balance
void MinimumAccountBalance(Container &data);
#endif // FUNCTIONALITIES_H
