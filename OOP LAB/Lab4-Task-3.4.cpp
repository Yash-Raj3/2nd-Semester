#include<iostream>
using namespace std;
class student{
	private:
	string name;
	int id;
	float gpa;
	public:
	student(string name,int id,float gpa){
		// This Pointer provide clarity between parameters and attributes which have same name. 
		//In this name,id,gpa are same as attributes. So, It can create confusion for compiler
		// we use this which always points toward the member attributes 
		this->name = name;
		this->id = id;
		this->gpa = gpa;
	}
	void print(){
		cout<<name<<endl<<id<<endl<<gpa;
	}
}; 
int main(){
	student s1("Harshit",234,3.5);
	s1.print();
}
