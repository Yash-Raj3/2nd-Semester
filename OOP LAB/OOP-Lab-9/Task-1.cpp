#include<iostream>
using namespace std;
class transaction{
	protected:
	string	accNumber;
	double Balance;
	public:
		transaction(string num,double a){
			accNumber = num;
			Balance = a;
			
		}
		virtual void processTrasaction(double a)=0;
	
	
};
class deposit :public transaction{
	public:
	deposit(string num,double a ):transaction(num,a){}
	
	void processTrasaction(double a){
		if(a >= 0){
			Balance += a;
			cout<<"\n----Deposit Transaction----\n";
			cout<<"Account Number: "<<accNumber<<endl;
			cout<<"Amount: "<<a<<endl;
			cout<<"Status: Amount Deposited Successfully"<<endl;
			cout<<"New Balance: "<<Balance<<endl;
		}else{
			cout<<"Amount Must be Positive!\n";
			
		}
		cout<<"\n---------------------------------\n";
	}
};
class Withdraw: public transaction{
		public:
	Withdraw(string num,double a ):transaction(num,a){}
	
	void processTrasaction(double a){
		if(Balance >= a){
			Balance -= a;
			cout<<"\n----Withdraw Transaction----\n";
			cout<<"Account Number: "<<accNumber<<endl;
			cout<<"Amount: "<<a<<endl;
			cout<<"Status: Amount Withdrawn Successfully"<<endl;
			cout<<"New Balance: "<<Balance<<endl;
		}else{
			cout<<"Balance Insufficient!\n";
			
		}
		cout<<"\n---------------------------------\n";
	}
};
class transfer: public transaction{
		public:
	transfer(string num,double a ):transaction(num,a){}
	
	void processTrasaction(double a){
		string acc;
		cout<<"Enter Account Number To Transfer: ";
		cin>>acc;
		if(Balance >= a){
			
			Balance -= a;
			cout<<"\n----Transfer Transaction----\n";
			cout<<"Reciever Account Number: "<<accNumber<<endl;
			cout<<"Sender Account Number: "<<acc<<endl;
			cout<<"Amount: "<<a<<endl;
			cout<<"Status: Amount Transfered Successfully"<<endl;
			cout<<"New Balance: "<<Balance<<endl;
		}else{
			cout<<"Balance Insufficient!\n";
			
		}
		cout<<"\n---------------------------------\n";
	}
}; 
int main(){
	transaction *t;
	deposit d1("PXBX00981002",12000);
	t= &d1;
	t->processTrasaction(100);
	
	Withdraw w1("PXBTY3340",13000);
	t =&w1;
	t->processTrasaction(300);
	
	transfer tf("PXYB6679",14000);
	t =&tf;
	t->processTrasaction(14100);
}
