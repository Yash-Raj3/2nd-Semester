#ifndef Vehicle_H
#define Vehicle_H
#include <string>
using namespace std;
class Location
{
private:
	string city;
	string area;
	string province;
	string country;
	int zipcode;

public:
	Location();
	Location(string country, string province, string city, string area, int zipcode);
	// void setCity(string city);
	// void setArea(string area);
	// void setProvince(string province);
	// void setCountry(string country);
	// void setZipCode(int zc);
	string getCity();
	string getArea();
	string getProvince();
	string getCountry();
	int getZipCode();
	void Displaylocation() const;
	void updatelocation();
	bool isSameCity(const Location &other);
	bool isSameProvince(const Location &other);
};
class Engine
{
private:
	const string engineNumber;
	int horsepower;
	int torque;
	int capacity;
	string engineType;

public:
	Engine();
	Engine(string Enumber, int hp, int torque, int Ecap, string type);

	int getHP();
	int getcapacity();
	string getEngineNumber();

	double performanceScore();
	bool isPowerfulthan(const Engine &other);
	int calculateAge(int BuyingYear, int CurrentYear);
	void displaySpecs() const;
};
class Car
{
private:
	string brand;
	string model;
	int year;
	double price;
	float mileage;
	string transmission;
	Engine engine;
	Location location;
	bool PremiumCategory;

public:
	Car();
	Car(string brand, string model, int year, double price, float mileage, string transmission, Engine e, Location loc);
	Car(const Car &car);

	string getBrand();
	double getPrice();
	int getYear();
	float getmileage();
	void setMileage(float mil);
	string getmodel();
	void displayCarDetails() const;
	bool isPremium();
	void updatePrice();
	void CompareCarPrice(const Car &other);
};

#endif
