#include<iostream>
using namespace std;
class Employee{
	public:
	int id;
	float salary;
	void showEmployee(){
		cout<<id<<endl;
	}
	};
class Manager:public Employee{
	public:
	float bonus;
	void showManager(){
		cout<<(salary+bonus)<<endl;
	}
};
int  main(){
	
	Manager  m1;
	m1.id = 1234;
	m1.bonus = 12000;
	m1.salary = 34000;
	m1.showEmployee();
	m1.showManager();
}
