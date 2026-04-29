#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream dataFile;
    dataFile.open("data.txt", ios::app);
    string name;
    int age;
    if (!dataFile)
    {
        cout << "Error in Opening file" << endl;
    }
    else
    {
        cout << "Enter Your Name: ";
        getline(cin, name);
        cout << "Enter Your Age: ";
        cin >> age;
        dataFile << "Name: " << name << " Age: " << age << endl;
        dataFile.close();
        cout << "Data Written to File Successfully" << endl;
    }
}