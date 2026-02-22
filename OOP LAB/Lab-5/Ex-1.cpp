#include<iostream>
using namespace std;
class Car{
	string CarNumber;
	public:
	static int totalCars;
	Car(string CarNumber){
		this -> CarNumber =CarNumber;
		totalCars++;
	}
	void display(){
		cout<<CarNumber<<endl;
	}
	static void CarCounter(){
		cout<<totalCars;
	}
};
int Car::totalCars=0;
int main(){
	Car C1("Pk6667");
	Car C2("RTY667");
	C1.display();
	C2.display();
	
	Car::CarCounter();
	
}
