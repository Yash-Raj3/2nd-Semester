#include <iostream>
using namespace std;
template <typename T>
T add(T a, T b)
{
    return a + b;
}
template <typename T>
T diff(T a, T b)
{
    return a - b;
}
template <typename T>
T Product(T a, T b)
{
    return a * b;
}

int main()
{
    int a = 10, b = 20;
    cout << "The sum is: " << add(a, b) << endl;
    cout << "The difference is: " << diff(a, b) << endl;
    cout << "The product is: " << Product(a, b) << endl;

    double x = 5.5, y = 3.3;
    cout << "The sum is: " << add(x, y) << endl;
    cout << "The difference is: " << diff(x, y) << endl;
    cout << "The product is: " << Product(x, y) << endl;

    return 0;
}