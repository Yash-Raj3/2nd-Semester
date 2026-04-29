#include <iostream>
using namespace std;

template <typename T>
T getMin(T a, T b)
{
    return a < b ? a : b;
}

int main()
{
    int a = 10, b = 20;
    cout << "The smaller number is: " << getMin(a, b) << endl;

    double x = 5.5, y = 3.3;
    cout << "The smaller number is: " << getMin(x, y) << endl;

    char c1 = 'A', c2 = 'B';
    cout << "The smaller character is: " << getMin(c1, c2) << endl;

    return 0;
}
