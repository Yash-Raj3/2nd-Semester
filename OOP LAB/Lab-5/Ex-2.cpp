#include<iostream>
using namespace std;
class BankAccount{
	string AccNumber;
	public:
		static float interest_rate;
	BankAccount(string AccNumber){
		this -> AccNumber = AccNumber;
	}
	 void Display(){
	 	cout<<AccNumber<<endl;
	 }
	 static void ShowInterestRate(){
	 	cout<<interest_rate;
	 }
};
float BankAccount::interest_rate = 3.5;
int main(){
	BankAccount B1("Yash15262");
	BankAccount B2("Yash67889");
	B1.Display();
	B2.Display();
	BankAccount::ShowInterestRate();
}
