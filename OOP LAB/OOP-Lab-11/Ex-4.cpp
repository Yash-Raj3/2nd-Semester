#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    fstream file("demo.txt", ios::out);
    try
    {
        if (!file)
        {
            throw "Error in opening file";
        }
        else
        {
            file << "File is Working properly" << endl;
            cout << "Data written to file successfully." << endl;
            file.close();
        }
    }
    catch (const char *message)
    {
        cout << message << endl;
    }
}