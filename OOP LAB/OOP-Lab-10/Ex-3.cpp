#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try
    {
        if (age < 18)
        {
            throw "You are Not Eligible";
        }
        cout << "You are Eligible" << endl;
    }
    catch (const char *message)
    {
        cout << message << endl;
        return 0;
    }
    cout << "Program is still running..." << endl;
}