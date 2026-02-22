#include<iostream>
using namespace std;
class Square{
	float side_length;
	public:
	Square(float l){
		side_length = l;
	}
	float CalculateArea() const{
		return side_length*side_length;
	}
	void displayArea(){
		cout<<"Area: "<<CalculateArea()<<endl;
	}
};
int main(){
	Square s1(4.5);
	Square s2(2.0);
	s1.displayArea();
	s2.displayArea();
}
