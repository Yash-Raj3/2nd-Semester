#include<iostream>
using namespace std;
class Shape{
	public:
		int area(int side){
			return side*side;
		}
		int area(int length,int width){
			return length*width;
		}
		double area(double radius){
			return 3.14*radius*radius;
		}
		
};
int main(){
	Shape square;
	Shape rectangle;
	Shape circle;
	cout<<"Area of Square: "<<square.area(25)<<endl;
	cout<<"Area of Rectangle: "<<rectangle.area(12,2)<<endl;
	cout<<"Area of circle: "<<circle.area(3.50)<<endl;
	
}
