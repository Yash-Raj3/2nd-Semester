#include<iostream>
using namespace std;
class driver{
	public:
		void Driver(){
			cout<<"Driver Drives the Car!"<<endl;
		}
};
class mechanic{
	public:
		void Mechanic(){
			cout<<"Mechanic Repairs the Car!"<<endl;
			
		}
};
class technician:public driver,public mechanic{
	public:
		void Technician(){
			cout<<"I can Do both!"<<endl;
		}
};
int main(){
	technician t1;
	t1.Driver();
	t1.Mechanic();
	t1.Technician();
}
