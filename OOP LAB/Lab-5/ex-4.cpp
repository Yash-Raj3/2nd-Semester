#include<iostream>
using namespace std;
class circle{
	public:
		float radius;
	circle(float r):radius(r){}
	
	float Area()const{
		return 3.14*radius*radius;
	}
};
int main(){
	circle c1(2.5);

	
	cout<<"Area: "<<c1.Area();
	
}
