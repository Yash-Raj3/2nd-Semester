#include<iostream>
using namespace std;
class Mechanic;
class CarEngine{
	private:
		int horseP;
	public:
		CarEngine(int hp){
			horseP=hp;
		}
		friend class Mechanic;
};
class Mechanic{
	public:
		void DisplayHP(CarEngine engine){
			cout<<"Horse Power: "<<engine.horseP<<endl;
		}
		void UpgradeHP( CarEngine &engine){
			while(true){
				cout<<"Enter HorsePower(100-1000): ";
				cin>>engine.horseP;
				if(engine.horseP > 100 && engine.horseP <1000){
					break;
				}else{
					cout<<"Must Be Between 100-1000!"<<endl;
				}
			}
		}
};
int main(){
	CarEngine engine(490);
	Mechanic m;
	m.DisplayHP(engine);
	m.UpgradeHP(engine);
	m.DisplayHP(engine);
}
