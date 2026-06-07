#include <iostream>
using namespace std;

class A
{
    int a;
    double b;

public:
    A()
    {
    }

    A(int x)
    {
        a = x;
        cout << "a: " << a << endl;
    }
    A(double y)
    {
        b = y;
        cout << "b: " << b << endl;
    }
    A(int x, double y)
    {
        a = x;
        b = y;
        cout << "a: " << a << ", b: " << b << endl;
    }
};
int main()
{
    A obj1;
    A obj2(10);
    A obj3(3.14);
    A obj4(20, 2.71);

    return 0;
}