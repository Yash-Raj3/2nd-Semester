#include<iostream>
using namespace std;
class Employee{
	public:
	 void CalculateSalary(){
	 	cout<<"Base Class"<<endl;
	 }
};
class Manager :public Employee{
	public:
	 void CalculateSalary(){
	 	cout<<"Manager Salary: 22500"<<endl;
	 }
};
class Developer: public Employee{
	public:
	 void CalculateSalary(){
	 	cout<<"Developer Salary: 25000"<<endl;
	 }
};
class Intern:public Employee{
	public:
	 void CalculateSalary(){
	 	cout<<"Intern Salary: 14000"<<endl;
	 }
};
int main(){
	Manager m;
	m.CalculateSalary();
	Developer d;
	d.CalculateSalary();
	Intern i;
	i.CalculateSalary();
	
}
