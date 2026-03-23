#include<iostream>
using namespace std;
class shape{
public:
	void draw(){
		cout<<"Draw the Shape"<<endl;
	}
};
class circle:public shape{
	public:
	 void  draw(){
	 	cout<<"Draw the circle"<<endl;
	 	
	 }
};
class rectangle:public shape{
	public:
		void draw(){
			cout<<"Draw the rectangle"<<endl;
		}
};
int main(){
	circle c;
	c.draw();
	rectangle r;
	r.draw();
}
