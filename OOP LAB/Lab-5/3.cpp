#include<iostream>
using namespace std;
class Vehicle{
	const int vehicleID;
	string modelName;
	public:
	Vehicle(string modelName,int ID):modelName(modelName),vehicleID(ID){}
	
	void displayInfo()const{
	cout<<"Model Name: "<<modelName<<endl;
	cout<<"Vehicle ID: "<<vehicleID<<endl;
	}
};
int main(){
	Vehicle v1("Honda City",345);
	v1.displayInfo();
}
