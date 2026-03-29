#include<iostream>
using namespace std;
class Discount{
	double discount;
	public:
		Discount(){
			discount = 0.2;
		}
	 double applydiscount(double cost){
	 	return cost -(discount * cost);
	 }
};
class device{
public:
	string name;
	double power;
	double hours;
	device(){
		name ="";
		power = 0;
		hours =0;
	}
	device(string n,double p,double h){
		name = n;
		power = p;
		hours = h;
	}
	void display(){
		cout<<"Name: "<<name<<", Power: "<<power<<" Watts"<<", Hours: "<<hours<<endl;
	}
	double calculateEnergyinKw(){
		return (power*hours)/1000;
	}
};
class EntertainmentRoom{
	int DeviceC;
	device d[5];
	public:
		EntertainmentRoom(){
			DeviceC= 0;
		}
		void addDevice(device other){
			if(DeviceC<5){
				d[DeviceC++]=other;
			}else{
				cout<<"Room is Full"<<endl;
			}
		}
		double calculateTotalEnergy(){
			double tEnergy= 0;
			for(int i=0;i<DeviceC;i++){
				tEnergy+= d[i].calculateEnergyinKw();
			}
			return tEnergy;
		}
		int findHighestEnergyD(){
			 double highest =d[0].calculateEnergyinKw();
			 int highestd=0;
			for(int i=0;i<DeviceC;i++){
				if(d[i].calculateEnergyinKw()>highest){
					highest = d[i].calculateEnergyinKw();
					highestd = i;
				}
				
			}
			return highestd;
		}
		void displayEnergySummary(){
			cout<<"-----DEVICES-----\n";
			
			for(int i=0;i<DeviceC;i++){
				d[i].display();
			}
			cout<<"Total Energy Used: "<<calculateTotalEnergy()<<endl;
			Discount dis;
			double bill = calculateTotalEnergy()*0.15;
			double billd = dis.applydiscount(bill);
			cout<<"Total Cost Before Discount: "<<bill<<endl;
			cout<<"Total Cost After Discount: "<<billd<<endl;
			cout<<"Highest Energy Consumer Device: ";
			d[findHighestEnergyD()].display();
		}
};
int main(){
	EntertainmentRoom er;
	device d1("TV",100,2.5);
	device d2("PS5",400,10);
	device d3("Sound System",200,8);
	er.addDevice(d1);
	er.addDevice(d2);
	er.addDevice(d3);
	er.displayEnergySummary();
	
	
}
