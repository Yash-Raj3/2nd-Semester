#include<iostream>
using namespace std;

class Employee{
	private:
		int id;
		float salary;
	public:
		Employee(){
			id =0;
			salary = 0;
		}
	void PrintDetails(){
		cout<<"Id: "<<id<<endl<<"Salary: "<<salary<<endl;
	}
};
int main(){
	Employee E1,E2,E3;
	E1.PrintDetails();
	E2.PrintDetails();
	E3.PrintDetails();
}
