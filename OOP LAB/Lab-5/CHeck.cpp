#include <iostream>
using namespace std;

class Patient
{
    const int patientID;
    string name;

public:
    // Default constructor (needed for array)
    Patient() : patientID(0), name("Unknown") {}

    // Parameterized constructor
    Patient(int id, string n) : patientID(id), name(n) {}

    void display() const
    {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "-------------------" << endl;
    }
};

class Hospital
{
    Patient patients[10];     // HAS-A relationship (array of objects)
    static int totalPatients; // static variable

public:
    void addPatient(int id, string name)
    {
        if (totalPatients < 10)
        {
            patients[totalPatients] = Patient(id, name);
            totalPatients++;
        }
        else
        {
            cout << "Hospital is full!" << endl;
        }
    }

    void displayAll() const
    {
        for (int i = 0; i < totalPatients; i++)
        {
            patients[i].display();
        }
    }

    static void displayTotalPatients()
    {
        cout << "Total Patients: " << totalPatients << endl;
    }
};

// Initialize static variable
int Hospital::totalPatients = 0;

int main()
{
    Hospital H1;

    // Creating 3 patients
    H1.addPatient(101, "Yash");
    H1.addPatient(102, "Mahboor");
    H1.addPatient(103, "Qasim");

    // Display all patients
    H1.displayAll();

    // Display total count
    Hospital::displayTotalPatients();

    return 0;
}
