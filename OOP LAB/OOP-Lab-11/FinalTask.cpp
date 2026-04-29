#include <iostream>
#include <fstream>
#include <string>

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
        getline(cin, name);
        cout << "Enter GPA: ";
        cin >> gpa;
        cin.ignore();
    }
    void add(fstream &studentfile)
    {
        studentfile << "ID: " << id << " Name: " << name << " GPA: " << gpa << endl;
    }
    static void search(fstream &studentfile)
    {
        string line;
        string searchName;
        cout << "Enter Name to search: ";
        getline(cin, searchName);
        bool found = false;
        while (getline(studentfile, line))
        {
            if (line.find(searchName) != string::npos)
            {
                cout << "Record found: " << line << endl;
                found = true;
            }
        }
        try
        {
            if (!found)
            {
                throw "Record not found.";
            }
        }
        catch (const char *message)
        {
            cout << message << endl;
        }
    }
    static void view(fstream &studentfile)
    {
        if (Scount == 0)
        {
            cout << "No records to display.\n";
            return;
        }
        string line;
        while (getline(studentfile, line))
        {
            cout << line << endl;
        }
    }
    static void initializeCount()
    {
        fstream studentfile("sfile.txt", ios::in);
        if (studentfile.is_open())
        {
            string line;
            while (getline(studentfile, line))
            {
                Scount++;
            }
            studentfile.close();
        }
    }
};
void display()
{
    cout << "1. Add Student\n";
    cout << "2. View All Students\n";
    cout << "3. Search Student\n";
    cout << "0. Exit\n";
}
int Student::Scount = 0;
int main()
{
    Student::initializeCount();
    fstream sfile;
    int choice = -1;

    while (choice != 0)
    {
        display();
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            sfile.open("sfile.txt", ios::app);
            try
            {
                if (!sfile)
                {
                    throw "Error in opening file";
                    return 1;
                }
                else
                {
                    Student s;
                    s.getData();
                    s.add(sfile);
                    sfile.close();
                }
            }
            catch (const char *message)
            {
                cout << message << endl;
            }

            break;
        case 2:
            sfile.open("sfile.txt", ios::in);
            try
            {
                if (!sfile)
                {
                    throw "Error in opening file";
                    return 1;
                }
                else
                {
                    Student::view(sfile);
                    sfile.close();
                }
            }
            catch (const char *message)
            {
                cout << message << endl;
            }
            break;
        case 3:
            sfile.open("sfile.txt", ios::in);
            try
            {
                if (!sfile)
                {
                    throw "Error in opening file";
                    return 1;
                }
                else
                {
                    Student::search(sfile);
                    sfile.close();
                }
            }
            catch (const char *message)
            {
                cout << message << endl;
            }

            break;
        case 0:
            cout << "Exiting....\n";
            break;
        default:
            cout << "Invalid Option!\n";
        }
    }
}
