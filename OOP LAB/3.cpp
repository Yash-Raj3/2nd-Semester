#include<iostream>
using namespace std;
void Square(int *num){
	*num *= *num;
}
int main(){
	int num =10;
	Square(&num);
	cout<<"Square is "<<num;
}
