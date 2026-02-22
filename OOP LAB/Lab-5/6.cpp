#include<iostream>
using namespace std;
class Product{
	string name;
	int id;
	float price;
	public:
	
	void Input(){
		cout<<"Enter Name: ";
		cin>>name;
		cout<<"Enter ID: ";
		cin>>id;
		cout<<"Enter Price: ";
		cin>>price;
	}
	void Display(){
		cout<<"Name: "<<name<<endl;
		cout<<"ID: "<<id<<endl;
		cout<<"Price: "<<price<<endl;
	}
};
int main(){
	Product p[4];
	for(int i=0;i<4;i++){
		cout<<"---- Enter Product "<<i+1<<" Details----"<<endl;
		p[i].Input();
	}
	for(int i=0;i<4;i++){
		cout<<"--- Product "<<i+1<<" ---"<<endl;
		p[i].Display();
	}
	
}
