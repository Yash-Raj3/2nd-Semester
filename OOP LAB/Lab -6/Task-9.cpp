#include<iostream>
using namespace std;
class Account{
	public:
	string accountNo;

		void showAccount(){
			cout<<"Account No: "<<accountNo<<endl;
		}

};

class SavingAccount:public Account{
	private:
		float amount;
		float interestRate;
	public:
		SavingAccount(float amount):interestRate(0.4){
			this ->amount =amount;
		}
		
		
	void CalculateInterest(){
		showAccount();
		cout<<"Interest: "<<amount*interestRate<<endl;
	}
};

class CurrentAccount:public Account
{
private:
    double balance;
    double overdraftLimit;

public:
    CurrentAccount(double b, double limit)
    {
        balance = b;
        overdraftLimit = limit;
    }

  void withdraw(double amount)
    {
        balance -= amount;
    }

    double calculateOverdraft()
    {
        if (balance < 0)
        {
            return -balance;   
        }
        return 0;            
    }

    void display()
    {
    	showAccount();
        cout << "Current Balance: " << balance << endl;
        cout << "Overdraft Used: " << calculateOverdraft() << endl;
    }
};
int main(){
	
	SavingAccount sa1(150000);
	sa1.accountNo ="PXB990000SBX";
	sa1.CalculateInterest();
	
	CurrentAccount ca1(5000,25000);
	ca1.accountNo="PXB990000SBX";
	ca1.withdraw(20000);
	ca1.calculateOverdraft();
	ca1.display();
	
	
	
	
}

