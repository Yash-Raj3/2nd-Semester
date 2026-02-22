#include<iostream>
using namespace std;

class Cpu{

	string generation;
	public:
	Cpu(string g){
		generation = g;
	}
	void DisplayInfo(){
		cout<<"CPU Gen: "<<generation<<endl;
	}
	
	
};
class Computer{
	string Model;
	string Brand;
	Cpu CPU;
	public:
	 Computer(string model,string brand,string Gen):Model(model),Brand(brand),CPU(Gen){}
	 
	 void DisplayInfo(){
	 	cout<<"Model: "<<Model<<endl;
	 	cout<<"Brand: "<<Brand<<endl;
	 	CPU.DisplayInfo();
	 }
};
int main(){
	Computer c1("Victus","HP","i7-13th");
	c1.DisplayInfo();
	
}
