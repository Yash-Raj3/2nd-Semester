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
    T div()
    {
        if (num2 == 0)
        {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
        return num1 / num2;
    }
};
int main()
{
    Calculator<int> c1(111, 110);
    cout << "The sum is: " << c1.add() << endl;
    cout << "The difference is: " << c1.sub() << endl;
    cout << "The product is: " << c1.mul() << endl;
    cout << "The Division is: " << c1.div() << endl;
    Calculator<double> c2(5.5, 3.3);
    cout << "The sum is: " << c2.add() << endl;
    cout << "The difference is: " << c2.sub() << endl;
    cout << "The product is: " << c2.mul() << endl;
    cout << "The Division is: " << c2.div() << endl;
}
