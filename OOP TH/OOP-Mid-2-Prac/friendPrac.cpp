#include<iostream>
using namespace std;
class demoB;
class H1;
class demoA{
	int x;
	int y;
	public:
		void bro(demoB other);
		demoA(int x=0,int y=0): x(x),y(y){}
		friend void Both(demoA A1,demoB B1);
};
class demoB{
	int a;
	int b;
	public:
		friend void demoA::bro(demoB other);
		demoB(int a=0,int b=0):a(a),b(b){}
		friend void Both(demoA A1,demoB B1);
};
void demoA::bro(demoB other){
	cout<<"I am B's Attribute a: "<<other.a<<endl;
}
void Both(demoA A1,demoB B1){
	cout<<"x: "<<A1.x<<" y: "<<A1.y<<endl;
	cout<<"a: "<<B1.a<<" b: "<<B1.b<<endl;
}

class H{
	int balance;
	void showBalance(){
		cout<<"Balance: "<<balance<<endl;
	}
	public:
		friend class H1;
		H(int amount){
			balance = amount;
		}
		void showH1(H1 h1);
	
};
class H1{
	int Balance;
	void show(){
		cout<<"Balance: "<<Balance<<endl;
	}
	public:
		friend class H;
		void showH(H h){
			cout<<"Balance of H: "<<h.balance<<endl;
			h.showBalance();
		}
		H1(int amount){
			Balance = amount;
		}
};
	void H::showH1(H1 h1){
			cout<<"Balance of H1: "<<h1.Balance<<endl;
			h1.show();
		}
int main(){
	demoA a(5,5);
	demoA a1(1,2);
	demoB b1(3,4);
	Both(a1,b1);
	demoB B(10,10);
	a.bro(B);
	H1 hh1(10000);
	H hh(20000);
	hh1.showH(hh);
	hh.showH1(hh1);
}
