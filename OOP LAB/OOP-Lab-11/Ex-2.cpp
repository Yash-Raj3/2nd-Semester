#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ofstream numFile;
    numFile.open("numbers.txt", ios::app);
    if (!numFile)
    {

        cout << "Error in opening file!" << endl;
        return 1;
    }
    else
    {
        int num;
        for (int i = 0; i < 10; i++)
        {
            cout << "Enter Number " << i + 1 << " : ";
            cin >> num;
            numFile << num << endl;
        }
        numFile.close();
        cout << "Numbers Written to File Successfully" << endl;
    }

    ifstream readFile;
    readFile.open("numbers.txt");
    if (!readFile)
    {
        cout << "Error in opening file!" << endl;
        return 1;
    }
    else
    {
        int number;
        cout << "EvenNumbers from File:" << endl;
        while (readFile >> number)
        {
            if (number % 2 == 0)
            {
                cout << number << endl;
            }
        }
        readFile.close();
    }
}
