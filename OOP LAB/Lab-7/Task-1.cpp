#include<iostream>
using namespace std;
class Calculator{
	public:
	int multiply(int a,int b ){
		return a*b;
	}
	int multiply(int a,int b,int c){
		return a*b*c;
		
	}
	double multiply(double a,double b){
		return a*b;
	}
};
int main(){
  Calculator obj;
    cout << obj.multiply(2,3) << endl;
    cout << obj.multiply(2,3,4) << endl;
    cout << obj.multiply(22.3,33.2) << endl;
}
