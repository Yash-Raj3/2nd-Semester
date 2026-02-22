#include<iostream>
using namespace std;
class schoolAccount{
	string name;
	int grade;
	static float tutionfee;
	public:
	schoolAccount(string name,int grade){
		this->name = name;
		this->grade = grade;
	}
	void displayInfo(){
		cout<<"Name: "<<name<<endl;
		cout<<"Grade: "<<grade<<endl;
	}
	static void showfee(){
		cout<<tutionfee;
	} 
};
float schoolAccount::tutionfee = 3567.5;
int main(){
	schoolAccount a1("Yash",7);
	schoolAccount a2("Harsh",6);
	a1.displayInfo();a2.displayInfo();
	schoolAccount::showfee();
} 
