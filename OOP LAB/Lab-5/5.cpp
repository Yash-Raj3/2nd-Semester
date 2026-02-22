#include<iostream>
using namespace std;
class SIM{
	int strength;
	public:
	SIM(int s):strength(s){}
	void ShowCarrier(){
		cout<<"Strength: "<<strength<<endl;
	}
	
};
class Phone{
	string model;
	SIM sim1;
	public:
	Phone(string model,int s):model(model),sim1(s){}
	void display(){
		cout<<"Model: "<<model<<endl;
		sim1.ShowCarrier();
	}
};
int main(){
	Phone p1("Redmi Note 13",3);
	Phone p2("Samsung s22",4);
	p1.display();p2.display();
}
