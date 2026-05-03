#include <iostream>
using namespace std;

class Subject
{
    string subjectname;

public:
    Subject(string subjectname = "")
    {
        if (subjectname == "")
        {
            subjectname = "Unknown";
        }
        else
        {
            this->subjectname = subjectname;
        }
    }
    void setname(string sname)
    {
        if (sname == "")
        {
            subjectname = "Unknown";
        }
        else
        {
            this->subjectname = sname;
        }
    }
    string getname()
    {
        return subjectname;
    }
};
class Teacher
{
protected:
    int id;
    string name;

public:
    Teacher(int id = 0, string name = "")
    {
        this->id = id;
        this->name = name;
    }
};
class SeniorTeacher : public Teacher
{

    static int SeniorTeacherCount;
    Subject s;

public:
    SeniorTeacher(int id = 0, string name = "") : Teacher(id, name)
    {
        if (SeniorTeacherCount < 10)
        {
            SeniorTeacherCount++;
        }
        else
        {
            cout << "Cannot create more than " << 10 << " Senior Teachers." << endl;
        }
    }
    static int getSeniorTeacherCount()
    {
        return SeniorTeacherCount;
    }
    void assignClass(string classname)
    {
        cout << "Class " << classname << " is assigned to Senior Teacher with ID: " << id << endl;
    }
    void assignclass(string classname, int roomNumber)
    {
        cout << "Class " << classname << " is assigned to Senior Teacher with ID: " << id << " in room number " << roomNumber << endl;
    }
    void assignSubject(Subject subject)
    {
        s = subject;
        cout << "Subject " << s.getname() << " is assigned to Senior Teacher with ID: " << id << endl;
    }
};
int SeniorTeacher::SeniorTeacherCount = 0;
int main()
{
    SeniorTeacher t[3];
    for (int i = 0; i < 3; i++)
    {
        string name;
        cout << "Enter Name of Senior Teacher " << i + 1 << ": ";
        cin >> name;
        t[i] = SeniorTeacher(i + 1, name);
    }
    Subject s[10];
    for (int i = 0; i < 3; i++)
    {
        string subjectname;
        cout << "Enter Subject name for Senior Teacher " << i + 1 << ": ";
        cin >> subjectname;
        s[i] = Subject(subjectname);
        t[i].assignSubject(s[i]);
    }
    for (int i = 0; i < 2; i++)
    {
        string classname;
        cout << "Enter Class name for Senior Teacher " << i + 1 << ": ";
        cin >> classname;
        t[i].assignClass(classname);
    }
    for (int i = 2; i < 3; i++)
    {
        string classname;
        int roomNumber;
        cout << "Enter Class name for Teacher " << i + 1 << ": ";
        cin >> classname;
        cout << "Enter Room number for Teacher " << i + 1 << ": ";
        cin >> roomNumber;
        t[i].assignclass(classname, roomNumber);
    }

    cout << "Total number of Senior Teachers: " << SeniorTeacher::getSeniorTeacherCount() << endl;
}