#include <iostream>
using namespace std;

class A
{
public:
    void perform()
    {
        cout << "Hello World!" << endl;
    }
};
class B : public A
{
    int x;

public:
    void perform(int a)
    {
        x = a;
        cout << "Value of x: " << x << endl;
    }
};
class C : public B
{
public:
    string name;
    void perform(string n)
    {
        name = n;
        cout << "Name: " << name << endl;
    }
};
int main()
{

    C obj;

    obj.perform("John Doe");
}