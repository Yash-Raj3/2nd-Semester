#include<iostream>
using namespace std;
class Box{
	public:
		float height;
	Box(float h){
		height = h;
		cout<<"Parameterized Comstructor Here"<<endl;
	}
	
	Box(Box & b){
		height = b.height;
		cout<<"Copy Constructor Here!"<<endl;
	}
	void Display(){
		cout<<height<<endl;
	}
};
int main(){
	Box B1(5.6);
	B1.Display();
	Box B2(B1);
	B2.Display();
}
