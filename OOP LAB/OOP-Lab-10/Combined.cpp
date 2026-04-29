#include <iostream>
using namespace std;
template <class T>

class Calculator
{
    T num1, num2;

public:
    Calculator(T a, T b)
    {
        num1 = a;
        num2 = b;
    }
    T add()
    {
        return num1 + num2;
    }
    T sub()
    {
        return num1 - num2;
    }
    T mul()
    {
        return num1 * num2;
    }
    void div()
    {
        try
        {
            if (num2 == 0)
            {
                throw "Cannot divide by zero!";
            }
            cout << "The Division is: " << num1 / num2 << endl;
        }
        catch (const char *message)
        {
            cout << message << endl;
        }
    }
};
int main()
{
    Calculator<int> c1(111, 0);
    cout << "The sum is: " << c1.add() << endl;
    cout << "The difference is: " << c1.sub() << endl;
    cout << "The product is: " << c1.mul() << endl;
    c1.div();
    Calculator<double> c2(5.5, 3.3);
    cout << "The sum is: " << c2.add() << endl;
    cout << "The difference is: " << c2.sub() << endl;
    cout << "The product is: " << c2.mul() << endl;
    c2.div();
}