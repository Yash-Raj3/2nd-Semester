#include<iostream>
using namespace std;
class Rectangle{
	private:
		double length;
		double width;
	public:
		void GetInput(){
			while(true){
			cout<<"Enter Length: ";
			cin>>length;
			cout<<"Enter Width: ";
			cin>>width;
			if(width >=0 && length >=0){
				break;
			}else{
				cout<<"These Values Can't be Negative!"<<endl;
			}
		}
		}
		friend void Perimeter(Rectangle r1);
		friend void Area(Rectangle r1);
};
void Perimeter(Rectangle r1){
	cout<<"Perimeter: "<<(2*r1.length)+(2*r1.width)<<endl;
}
void Area(Rectangle r1){
	cout<<"Area: "<<r1.length*r1.width<<endl;
}
int main(){
	Rectangle r;
	r.GetInput();
	Perimeter(r);
	Area(r);
}
