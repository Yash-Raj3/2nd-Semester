#include<iostream>
using namespace std;
class shape{
	public:
		float PI = 3.14;
		float radius;
};
class Circle:public shape{
	public:
		float area;
		void Area(){
			area=	PI*radius*radius;
			cout<<"Area: "<<area<<endl;
		}
};
int main(){
	Circle c1;
	c1.radius = 12;
	c1.Area();
	
}
