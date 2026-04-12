#include <iostream>
using namespace std;
class LibraryBook
{
private:
	string title;
	string author;
	bool isIssue;

public:
	LibraryBook(string t, string a)
	{
		title = t;
		author = a;
		isIssue = false;
	}
	friend class Librarian;
};
class Librarian
{
public:
	
	void Issue(LibraryBook &b)
	{
	
			if (b.isIssue == false)
			{
			
				b.isIssue = true;
				cout << "Book Issued" << endl;
			}else{
				cout<<"Book is Already Issued"<<endl;
			}
		}
	
	void ShowBook(LibraryBook b){
		cout<<"Title: "<<b.title<<" Author: "<<b.author<<endl;
		
	}
};
int main()
{
	LibraryBook b1("Hero", "Yash");
	Librarian l1;
	l1.Issue(b1);
	l1.ShowBook(b1);
	Librarian l2;
	l2.Issue(b1);
	LibraryBook b2("Animal Farm","George Orwell");
	l2.Issue(b2);
	l2.ShowBook(b2);
	
}
