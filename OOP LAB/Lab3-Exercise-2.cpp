#include<iostream>
using namespace std;
 class Rectangle{
 	private:
 	 float length;
 	 float width;
 	 
 	 public:
 	 	Rectangle(float x,float y){
 	 		length = x;
 	 		width =y;
 	 		
		  }
		float area(){
			return length * width;
			
		}
		void print (){
			cout <<"Length: "<<length<<endl<<"Width: "<<width<<endl;
			cout <<"Area: "<<area()<<endl;
		}
 };
 int main(){
 	Rectangle r1(11.2,98.3);
 	r1.print();
 	Rectangle r2(12.6,87.3);
 	r2.print();
 }
