#include<iostream>
using namespace std;
class LibraryMember{
	string name;
	static int totalmember;
	public:
	LibraryMember(string n){
		name = n;
		totalmember++;
	}
	void displayName(){
		cout<<"Name: "<<name<<endl;
	}
	static void displaytotalmember(){
		cout<<totalmember;
	}
};
 int LibraryMember::totalmember = 0;
int main(){
	LibraryMember m1("Yash");
	LibraryMember m2("Harsh");
	LibraryMember m3("Aisha");
	LibraryMember m4("Usman");
	m1.displayName();m2.displayName();m3.displayName();m4.displayName();
	LibraryMember::displaytotalmember();
	
	
	
}
