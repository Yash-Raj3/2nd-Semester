#include<iostream>
using namespace std;
class BankAccount
{
public:
    int balance;

    void showBalance()
    {
        cout << "Balance: " << balance << endl;
    }
};
class SavingsAccount : private BankAccount
{
public:
    void setBalance(int b)
    {
        balance = b;   
    }

    void display()
    {
        showBalance(); 
    }
};
int main()
{
    SavingsAccount s;

    s.setBalance(5000);
    s.display();

    // s.balance = 5000;      // Not accessible
    // s.showBalance();       // Not accessible
}
