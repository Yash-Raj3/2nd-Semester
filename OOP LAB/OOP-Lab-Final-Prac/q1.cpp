#include <iostream>
using namespace std;

class ElectricityBill
{
private:
	const int Cid;
	string Cname;
	double units;
	static int totaluser;
	int rate;

public:
	ElectricityBill() : Cid(totaluser++), rate(15)
	{
		Cname = "";
		units = 0.0;
	}
	ElectricityBill(string name, double u) : Cid(totaluser++), rate(15)
	{
		Cname = name;
		units = u;
	}
	~ElectricityBill() {}
	int getCid() const
	{
		return Cid;
	}
	string getCname() const
	{
		return Cname;
	}
	double getUnits() const
	{
		return units;
	}
	double getRate() const
	{
		return rate;
	}
	void setName()
	{
		cout << "Enter the name of the customer: ";
		cin >> Cname;
	}
	void setUnits(double u)
	{
		if (u > 0)
		{
			units = u;
		}
		else
		{
			units = 0.0;
		}
	}
	void setRate(int r)
	{
		if (r > 0)
		{
			rate = r;
		}
		else
		{
			rate = 15;
		}
	}
	void inputdetails()
	{
		setName();
		double u;
		cout << "Enter number of units: ";
		cin >> u;
		setUnits(u);
		int r;
		cout << "Enter rate per unit: ";
		cin >> r;
		setRate(r);
	}
	double calculateBill() const
	{
		return units * rate;
	}
	void displayBill() const
	{
		cout << "Customer ID: " << Cid << endl;
		cout << "Customer Name: " << Cname << endl;
		cout << "Units Consumed: " << units << endl;
		cout << "Rate per Unit: " << rate << endl;
		cout << "Total Bill Amount: " << calculateBill() << endl;
	}
};
int ElectricityBill::totaluser = 5000;
int main()
{
	ElectricityBill bill1;
	bill1.inputdetails();
	bill1.displayBill();
}