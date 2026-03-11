#include<iostream>
using namespace std;
class Person{
	public:
		string name;
		
};

class Employee:public Person{
	public:
		float salary;
};

class Developer:public Employee{
	public:
		string programmingLan;
		void DisplayDetails(){
			cout<<name<<endl;
			cout<<salary<<endl;
			cout<<programmingLan<<endl;
			
		}
};
int main(){
	Developer d1;
	d1.name = "Yash";
	d1.programmingLan ="C++";
	d1.salary = 120000;
	d1.DisplayDetails();
	
	
}
