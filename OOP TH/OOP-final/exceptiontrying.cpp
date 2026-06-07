#include <iostream>
using namespace std;

class Erroroccured : public exception
{
public:
    const char *what() const noexcept
    {
        return "An error occurred!";
    }
};
int main()
{
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    int c;
    try
    {
        if (b == 0)
        {
            throw Erroroccured();
        }
        c = a / b;
    }
    catch (const Erroroccured &e)
    {
        cerr << e.what() << endl;
    }
}