#include<iostream>
using namespace std;
class write{
	public:
		void Write(){
			cout<<"Author writes!"<<endl;
		}
};
class speaker{
	public:
		void speak(){
			cout<<"Author speaks!"<<endl;
		}
};
class author:public write,public speaker{
	public:
		void Author(){
		cout<<"I am author!"<<endl;
	}
};	
int main(){
	author a1;
	a1.speak();
	a1.Write();
	a1.Author();
	
	
}
