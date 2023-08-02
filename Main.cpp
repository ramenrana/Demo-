#include "Account.h"
#include "SavingsAccount.h"
#include "CurrentAccount.h"
#include "CurrentAccountType.h"
#include "SavingsAccountType.h"
#include "Functionalities.h"
#include <memory>
#include <list>

using contain=std::list<std::unique_ptr<Account>>;
int main(){
    contain acc;
    CreateObject(acc);
    std::cout<<AverageOFAllBalance(acc);
}