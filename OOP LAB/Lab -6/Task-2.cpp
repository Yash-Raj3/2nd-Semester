#include<iostream>
using namespace std;
class Vehicle{
	public:
		
	string brand;
	float speed;
	void showVehicle() {
		cout<<brand<<endl<<speed<<endl;
	}
};
class Car:public Vehicle{
	public:
		string fuelType;
	void showCarDetails(){
		cout<<fuelType<<endl;
		
	}
};
int main(){
	Car c1;
	c1.brand = "Toyota";
	c1.speed = 120;
	c1.fuelType ="Petrol";
	c1.showCarDetails();
	c1.showVehicle();
}
