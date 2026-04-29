#include <iostream>
#include <fstream>
using namespace std;
class Student
{
    double gpa;
    const int id;
    string name;
    static int Scount;

public:
    Student() : id(++Scount) {}
    void getData()
    {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter GPA: ";
        cin >> gpa;
    }
    void writeToFile(fstream &studentfile)
    {

        studentfile << "ID: " << id << " Name: " << name << " GPA: " << gpa << endl;
    }
    void display(fstream &studentfile)
    {

        string line;
        while (getline(studentfile, line))
        {
            cout << line << endl;
        }
    }
};
int Student::Scount = 0;
int main()
{
    Student s[5];
    fstream studentfile;
    studentfile.open("students.txt", ios::out);
    if (!studentfile)
    {
        cout << "Error in opening file";
        return 1;
    }
    else
    {
        for (int i = 0; i < 5; i++)
        {
            s[i].getData();
            s[i].writeToFile(studentfile);
        }
        cout << "Data written to file successfully." << endl;
        studentfile.close();
        studentfile.open("students.txt", ios::in);
        for (int i = 0; i < 5; i++)
        {
            s[i].display(studentfile);
        }
        cout << "Data displayed from file successfully." << endl;
        studentfile.close();
    }
}