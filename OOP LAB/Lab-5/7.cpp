#include <iostream>
using namespace std;
class Patient
{
	string name;
	const int P_ID;

public:
		Patient(string name, int id) : P_ID(id), name(name) {}

	void display() const
	{
		cout << "Name: " << name << endl;
		cout << "ID: " << P_ID << endl;
	}
};
class Hospital
{
	Patient *P[10];
	static int PatientCount;

public:
	void addNewPatient(string name, int id)
	{
		if (PatientCount < 10)
		{
			P[PatientCount] = new Patient(name, id);
			PatientCount++;
		}
		else
		{
			cout << "Limit is Over" << endl;
		}
	}
	void displayAll()
	{
		for (int i = 0; i < PatientCount; i++)
		{
			P[i]->display();
		}
	}
	static void totalPatients()
	{
		cout << PatientCount << endl;
	}
};
int Hospital::PatientCount = 0;
int main()
{
	Hospital H1;
	H1.addNewPatient("Yash", 998);
	H1.addNewPatient("Mahboor", 977);
	H1.addNewPatient("Qasim", 888);
	H1.displayAll();
	cout << "Total Patients: ";
	Hospital::totalPatients();
}
