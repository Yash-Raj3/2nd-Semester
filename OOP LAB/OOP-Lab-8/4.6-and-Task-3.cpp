#include<iostream>
using namespace std;
class Person{
	protected:
			int id;
		string name;
	public:
	
		Person(int id,string n):id(id),name(n){}
		void displayPerson(){
			cout<<"Id: "<<id<<endl<<"Name: "<<name<<endl;
		}
};
// Without Virtual
class EmployeeNV:public Person{
	protected:
		double salary;
	public:
	EmployeeNV(int id,string name,double salary):Person(id,name){
		this-> salary = salary;
	}
	void displayEmployee(){
		cout<<"Salary: "<<salary<<endl;
	}
};
class StudentNV: public Person{
	protected:
		double gpa;
		public:
			StudentNV(int id,string name,double gpa):Person(id,name){
				this->gpa =gpa;
			}
			void displayStudent(){
				cout<<"GPA: "<<gpa<<endl;
			}
};
class TANV: public EmployeeNV,public StudentNV{
	public:
		TANV(int id,string name,double salary,double gpa):EmployeeNV(id,name,salary),
		StudentNV(id,name,gpa){}
		void display(){
//			displayPerson(); Ambiguous call 
			EmployeeNV::displayPerson();
			// We are calling Display Person from a single class,so, No ambiguous call
			displayStudent();
			displayEmployee();
		}
};
// with Virtual
class Employee:virtual public Person{
	protected:
		double salary;
	public:
	Employee(int id,string name,double salary):Person(id,name){
		this-> salary = salary;
	}
	void displayEmployee(){
		cout<<"Salary: "<<salary<<endl;
	}
};
class Student:virtual public Person{
	protected:
		double gpa;
		public:
			Student(int id,string name,double gpa):Person(id,name){
				this->gpa =gpa;
			}
			void displayStudent(){
				cout<<"GPA: "<<gpa<<endl;
			}
};
class TA: public Employee,public Student{
	public:
		TA(int id,string name,double salary,double gpa):Person(id,name),Employee(id,name,salary),
		Student(id,name,gpa){}
		void display(){
			displayPerson();
			displayStudent();
			displayEmployee();
		}
};
int main(){
	cout<<"---Without Virtual---\n";
	TANV t1(2,"Yash",23333,1.2);
   t1.display(); 
	cout<<"---With Virtual---\n";
	TA ta(1,"Yash",20000,2.9);
	ta.display();
}
