#include<iostream>


using namespace std;
class Book{
	public:
	const string ISBN;
	Book(string isbn):ISBN(isbn){}
	
	void Display() const{
		cout<<ISBN<<endl;
	}
};
int main(){
	Book B1("Taare-Zameen-24536");
	Book B2("Harry-Puttar-4567");
	
	B1.Display();
	B2.Display();
}
