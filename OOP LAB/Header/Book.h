#ifndef BOOK_H
#define BOOK_H
#include<string>
using namespace std;

class Book{
	private:
	string Title;
	string Author;
	float Price;
	public:
	void setInfo(string title,string author,float price);
	void getInfo();
};
#endif  
