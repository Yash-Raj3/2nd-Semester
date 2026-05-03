#include <iostream>
#include <fstream>
using namespace std;
class Vehicle
{
protected:
	string Vnumber;
	string owner;
	double Scost;

public:
	Vehicle(string number = "", string o = "Unknown", double Sc = 0)
	{
		Vnumber = number;
		owner = o;
		try
		{
			if (Sc < 0)
			{
				throw "Service Cost Must be Positive";
			}
			else
			{
				Scost = Sc;
			}
		}
		catch (const string *mesg)
		{
			cout << "Error: " << mesg << endl;
		}
	}
	virtual double calculateService() = 0;
	double operator+(const Vehicle &v)
	{
		return Scost + v.Scost;
	}
	friend void Display(const Vehicle &v);
	void SavetoFile(Vehicle &v)
	{
		fstream datafile("data.txt", ios::app);
		try
		{
			if (!datafile)
			{
				throw "Error in Opening File";
			}
			else
			{
				datafile << "Vehicle Number: " << v.Vnumber << ", Owner: " << v.owner << ", Service Cost: " << v.Scost << endl;
			}
		}
		catch (const string *mesg)
		{
			cout << mesg << endl;
		}
	}
};
void Display(const Vehicle &v)
{
	cout << "Vehicle Number: " << v.Vnumber << endl;
	cout << "Onwer: " << v.owner << endl;
	cout << "Service Cost: " << v.Scost << endl;
}

class Car : public Vehicle
{
public:
	Car(string n, string o, double c) : Vehicle(n, o, c) {}
	double calculateService()
	{
		return Scost += 2000;
	}
};
class Bike : public Vehicle
{
public:
	Bike(string n, string o, double c) : Vehicle(n, o, c) {}
	double calculateService()
	{
		return Scost += 1500;
	}
};
class Truck : public Vehicle
{
public:
	Truck(string n, string o, double c) : Vehicle(n, o, c) {}
	double calculateService()
	{
		return Scost += 2500;
	}
};
int main()
{
	Vehicle *v1 = new Car("BXA100", "Yash", 1200);
	Vehicle *v2 = new Bike("AWM120", "Mahboor", 200);
	Vehicle *v3 = new Truck("TRK500", "Shoaib", 3000);
	v1->calculateService();
	v2->calculateService();
	v3->calculateService();
	Display(*v1);
	Display(*v2);
	Display(*v3);
	cout << "Total Service Cost of V1 and V2: " << (*v1 + *v2) << endl;

	v1->SavetoFile(*v1);
	v2->SavetoFile(*v2);
	v3->SavetoFile(*v3);

	delete v1;
	delete v2;
	delete v3;
}
