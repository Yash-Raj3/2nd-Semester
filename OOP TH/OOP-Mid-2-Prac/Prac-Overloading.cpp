#include <iostream>
using namespace std;
class demo
{
public:
	int x;

	demo(int x) : x(x) {}
	bool operator == (demo other){
		if(x == other.x){
			return true;
		}
		return false;
	}
	void operator++(int)
	{
		x++;
	}
	demo & operator=(const demo &b)
	{
		x = b.x;
		return *this;
	}
	friend ostream &operator<<(ostream &out, const demo &a);
	friend istream &operator>>(istream &in,  demo &a);
};
ostream &operator<<(ostream &out, const demo &a)
{
	out << a.x << endl;
	return out;
}
istream &operator>>(istream &in, demo &a)
{
	cout << "Enter Value of a: ";
	in >> a.x;
	return in;
}
int main()
{
	demo a(10);

	cout << a;
	cin >> a;
	cout << a;
	a++;
	cout << a;
	demo b = a;
	cout << b;
	if(a == b){
		cout<<"Equal "<<endl;
		
	}else{
		cout<<"Not Equal"<<endl;
	}
}
