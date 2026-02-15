#include<iostream>
using namespace std;
 struct book{
	string title;
	string author;
	float price;
};
int main(){
	book b1;
	cout<<"Enter Book Title: ";
 	getline(cin,b1.title);
	cout<<"Enter Book Author: ";
	getline(cin,b1.author);
	cout<<"Enter Price Of Book: ";
	cin>>b1.price;
	cout<<"----------------"<<endl;
	cout<<"Book 1"<<endl;
	cout<<"Title: "<<b1.title<<endl;
	cout<<"Author: "<<b1.author<<endl;
	cout<<"Price: "<<b1.price<<endl;
	cout<<"----------------"<<endl;
}
