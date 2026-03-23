#include<iostream>
using namespace std;
class Complex{
	private:
		double real,img;
	public:
		Complex(double r,double i):real(r),img(i){}
		
		Complex operator + (Complex b){
			Complex c(0,0);
			c.real = real + b.real;
			c.img = img + b.img;
			return c;
		}
			Complex operator - (Complex b){
			Complex c(0,0);
			c.real = real - b.real;
			c.img = img - b.img;
			return c;
		}
			Complex operator * (Complex b){
			Complex c(0,0);
			c.real = real * b.real;
			c.img = img * b.img;
			return c;
		}
		void GetValues(){
			cout<<real<<"+"<<img<<"i"<<endl;
		}
};

int main(){
	Complex a(2,4);
	Complex b(3,4);
	Complex c = a+b;
	c.GetValues();
	Complex d = b-a;
	d.GetValues();
	Complex e = a*b;
	e.GetValues();
}
