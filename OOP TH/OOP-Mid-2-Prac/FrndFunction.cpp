#include<iostream>
using namespace std;
class FrndFunction{
	int number;
	public:
	 FrndFunction(int n):number(n){}
	 friend void see(FrndFunction f);
	 
};

void see(FrndFunction f){
	cout<<f.number;
}
int main(){
	FrndFunction f1(100);
	
	see(f1);
	
	
}
