#include <iostream>
using namespace std;

int main()
{
    int marks;
    cout << "Enter your marks: ";
    cin >> marks;
    try
    {
        if (marks < 0 || marks > 100)
        {
            throw "Invalid Marks! Marks Should be between 0-100.";
        }
        cout << "Your marks are: " << marks << endl;
    }
    catch (const char *message)
    {
        cout << message << endl;
        return 0;
    }
    cout << "Program is still running..." << endl;
}