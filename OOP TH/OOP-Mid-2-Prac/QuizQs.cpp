#include<iostream>
using namespace std;
class A{
	public:
		int value;
		A(int x){
			value = x;
		}
		void showValue(){
			cout<<"Value: "<<value<<endl;
		}
};
class B:virtual public A{
	public:
	B():A(10){
		value += 3; 
	}
};
class C : virtual public A{
	public:
		C():A(3){
			value += 3;
		}
};
class D: public B,public C{
	public:
	D():A(20){
		value += 5;
	}
};
int main(){
	D d;
	B b;
	b.showValue();
	d.showValue();
}
