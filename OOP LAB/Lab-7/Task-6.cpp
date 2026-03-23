#include<iostream>
using namespace std;
class Vehicle{
	public:
		virtual void startEngine(){
			cout<<"Vehicle Engine Started"<<endl;
		}
};
class Car:public Vehicle{
	public:
		void startEngine(){
			cout<<"Car Engine Started"<<endl;
		}
};
class Bike:public Vehicle{
	public:
		void startEngine(){
			cout<<"Bike Engine Started"<<endl;
		}
};
class Truck:public Vehicle{
	public:
		void startEngine(){
			cout<<"Truck Engine Started"<<endl;
		}
};
int main(){
	Vehicle *ptr;
	Bike b;
	Car c;
	Truck t;
	ptr = &b;
	ptr->startEngine();
	ptr = &c;
	ptr->startEngine();
	ptr= &t;
	ptr->startEngine();
	
}
