#include<iostream>
using namespace std;
class employee{
	int id;
	float salary;
	public:
	void SetDetails(int Id,float Salary){
		salary = Salary;
		id  =Id;
	}
	void Display(){
		cout<<id<<endl<<salary<<endl;
	}
};
int main(){
	employee e[5];
	for(int i=0;i<5;i++){
		e[i].SetDetails(i+1,37000.76);
	}
	for(int i=0;i<5;i++){
		e[i].Display();
	}
}
