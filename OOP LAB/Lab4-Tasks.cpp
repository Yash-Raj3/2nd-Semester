#include<iostream>
using namespace std;
class account{
	private:
		string accNumber;
		float balance;
	public:
		// Default constructor : It is called when no parameter are passed from main
		account(){
			accNumber = "00";
			balance = 0.0;
			cout<<"I am Default constructor"<<endl;
		}
		// Parameterized constructor : It is called when parameter are passed from main
	account(string accNumber,float balance){ 
		cout<<"I am Parameterized constructor"<<endl;
		this->accNumber = accNumber;
		this->balance = balance;
	}
	// Copy Constructor: It is called when objects are copied;
	account(const account & acc){
		cout<<"I am Copy Constructor"<<endl;
		this->accNumber = acc.accNumber;
		this->balance =acc.balance;
	}
	// It is a method for printing data
		void print(){
		cout<<"Account Number: "<<accNumber<<endl;
		cout<<"Balance: "<<balance<<endl;
		}
			
};
int main(){
	account a1;
	a1.print();// It will call default constructor
	account a2("PBZ100008798",9888.9);
	a2.print();// It will call parameterized constructor
	account a3(a2);
	a3.print();// It will call copy constructor
	
	
	
}

