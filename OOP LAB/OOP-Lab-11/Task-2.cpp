#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("task.txt", ios::out);
    if (!file)
    {
        cout << "Error in opening file";
        return 1;
    }
    else
    {
        string line;
        cout << "Enter a line of text: ";
        while (getline(cin, line) && line != "")
        {
            cout << "Enter a line of text: ";

            file << line << endl;
        }
    }
    file.close();
    file.open("task.txt", ios::in);
    if (!file)
    {
        cout << "Error in opening file";
        return 1;
    }
    else
    {
        string line;
        int lineCount = 0;
        while (getline(file, line))
        {
            lineCount++;
        }
        cout << "Number of lines in the file: " << lineCount << endl;
    }
    file.close();
}