#include<iostream>
using namespace std;
class University
{
protected:
    string uniName;

public:
    University(string name)
    {
        uniName = name;
    }

    void showUniversity()
    {
        cout << "University: " << uniName << endl;
    }
};
class Faculty : public University
{
protected:
    string facultyName;

public:
    Faculty(string uName, string fName)
        : University(uName)
    {
        facultyName = fName;
    }

    void showFaculty()
    {
        cout << "Faculty: " << facultyName << endl;
    }
};
class Administration
{
protected:
    string adminRole;

public:
    Administration(string role)
    {
        adminRole = role;
    }

    void showAdministration()
    {
        cout << "Administration Role: " << adminRole << endl;
    }
};


class HOD : public Faculty, public Administration
{
private:
    string hodName;

public:
    HOD(string uName, string fName, string role, string hName)
        : Faculty(uName, fName), Administration(role)
    {
        hodName = hName;
    }

    void showHOD()
    {
        cout << "HOD Name: " << hodName << endl;
    }

    void displayAll()
    {
        showUniversity();      
        showFaculty();         
        showAdministration();  
        showHOD();             
    }
};

int main()
{
    HOD h("FAST University", "Computer Science", "Academic Head", "Dr. Ahmed");

    h.displayAll();


}
