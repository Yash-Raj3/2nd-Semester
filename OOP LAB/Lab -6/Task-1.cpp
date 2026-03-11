#include<iostream>
using namespace std;
class person{
	public:
		string name;
		int age;

		void displayinfo(){
			cout<<name<<endl;
			cout<<age<<endl;
		}
};
class Student:public person{
	public:
		int roll_Number;
	
		void displayStudent(){
			
			cout<<roll_Number<<endl;
			
		}
};
int main(){
	Student s1;
	s1.name = "Yash";
	s1.age = 19;
	s1.roll_Number = 878;
	s1.displayinfo();
	s1.displayStudent();
}
