#include<iostream>
#include "Book.h"
using namespace std;

void Book::setInfo(string title,string author,float price){
	Title = title;
	Author = author;
	Price = price;
}
void Book::getInfo(){
	cout<<"Title: "<<Title<<endl;
	cout<<"Author: "<<Author<<endl;
	cout<<"Price: "<<Price<<endl;
}

int main(){
	Book b1;
	b1.setInfo("Animal Farm","George Orwell",350);
	b1.getInfo();
}
