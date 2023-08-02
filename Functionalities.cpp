#include "Functionalities.h"

// Check Container is Empty or not
bool Check(Container &data)
{
    if (data.empty())
    {
        return true;
    }
    return false;
}

// Create Objects of Type Account
void CreateObject(Container &data)
{
    if (Check(data))
    {
        std::runtime_error("Container is Empty");
    }
    data.emplace_back(std::make_unique<SavingsAccount>(111111, 6376.98f, 2000.00f, SavingsAccountType::METRO));
    data.emplace_back(std::make_unique<CurrentAccount>(222222, 87869.9f, 3000.00f, 87382.0f, CurrentAccountType::BASIC));
    data.emplace_back(std::make_unique<CurrentAccount>(333333, 76768.9f, 3067.00f, 87376.0f, CurrentAccountType::BASIC));
}

// Find The Average of all Account Balance
float AverageOFAllBalance(Container &data)
{
    float total = 0.0f;
    int count = 0;
    if (Check(data))
    {
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        total += (**i).getAccountBalance();
        count++;
    }
    return total / count;
}

// Find The Average of all Savings Account Balance
float AverageOfSavingsAccBalance(Container &data)
{
    float total = 0.0f;
    int count = 0;

    if (Check(data))
    {
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        try
        {
            SavingsAccount &obj = dynamic_cast<SavingsAccount &>(**i);
            total += obj.getAccountBalance();
            count++;
        }
        catch (std::bad_cast &obj)
        {
            std::cout << "Casting Failed\n";
        }
    }
    return total / count;
}

// Find Average Minimum Balance for all Current Account;
float AverageMinOfCurrentAcc(Container &data)
{
    float total = 0.0f;
    int count = 0;
    float min = 0.0f;

    if (Check(data))
    {
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        try
        {
            CurrentAccount &obj = dynamic_cast<CurrentAccount &>(**i);
            if (obj.getAccountBalance() < min)
            {
                total += min;
                count++;
            }
        }
        catch (std::bad_cast &obj)
        {
            std::cout << "Casting Failed\n";
        }
    }
    return total / count;
}

// Total Interest of All Account
float TotalInterest(Container &data)
{
    float total = 0.0f;
    if (Check(data))
    {
        std::runtime_error("Empty Container");
    }
    for (auto i = data.begin(); i != data.end(); i++)
    {
        try
        {
            CurrentAccount &obj = dynamic_cast<CurrentAccount &>(**i);
            SavingsAccount &obj1 = dynamic_cast<SavingsAccount &>(**i);

            total += obj.CalculateInterestAmount();
            total += obj1.CalculateInterestAmount();
        }
        catch (std::bad_cast &obj)
        {
            std::cout << "Casting Failed\n";
        }
    }
    return total;
}

// Find Account With Minimum Account Balance
void MinimumAccountBalance(Container &data)
{
    float min = 0.0f;
    if (Check(data))
    {
        std::runtime_error("Empty Container");
    }
    auto itr = data.begin();
    for (auto i = data.begin(); i != data.end(); i++)
    {
        try
        {
            if ((**i).getAccountBalance() < min)
            {
                min = (**i).getAccountBalance();
                itr = i;
            }
        }
        catch (std::bad_cast &obj)
        {
            std::cout << "Casting Failed\n";
        }
    }

    std::cout << **itr;
}
