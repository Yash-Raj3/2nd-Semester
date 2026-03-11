#include <iostream>
using namespace std;
class Person
{
protected:
    string name;

public:
    Person(string n = "Unknown")
    {
        name = n;
    }

    void displayPerson()
    {
        cout << "Name: " << name << endl;
    }
};
class Teacher : virtual public Person
{
public:
    Teacher(string n="") : Person(n) {}

    void teachCourse()
    {
        cout << name << " is teaching a course" << endl;
    }
};
class Admin : virtual public Person
{
public:
    Admin(string n="") : Person(n) {}

    void manageSchool()
    {
        cout << name << " is managing school records" << endl;
    }
};
class HeadTeacher : protected Teacher
{
public:
    HeadTeacher(string n) : Person(n), Teacher(n) {}

    void manageTeachers()
    {
        cout << name << " is managing all teachers" << endl;
    }
};
class Coordinator : public Teacher, public Admin
{
public:
    Coordinator(string n) : Person(n), Teacher(n), Admin(n) {}

    void organizeEvent()
    {
        cout << name << " is organizing school event" << endl;
    }
};
class Student : public Person
{
public:
    Student(string n) : Person(n) {}

    void enrollCourse()
    {
        cout << name << " enrolled in a course" << endl;
    }
};
class OfficeAdmin : private Person
{
public:
    OfficeAdmin(string n) : Person(n) {}

    void showAdmin()
    {
        displayPerson();
        cout << "Handling office administration" << endl;
    }
};
int main()
{
    cout << "---- Student ----" << endl;
    Student s("Ali");
    s.displayPerson();
    s.enrollCourse();

    cout << "\n---- Coordinator ----" << endl;
    Coordinator c("Mr Ahmed");
    c.displayPerson();
    c.teachCourse();
    c.manageSchool();
    c.organizeEvent();

    cout << "\n---- Head Teacher ----" << endl;
    HeadTeacher h("Mrs Sara");
    h.manageTeachers();

    cout << "\n---- Office Admin ----" << endl;
    OfficeAdmin a("Mr Khan");
    a.showAdmin();

}
