#include <iostream>
#include <cstring>
#include "Vehiclesystem.h"
using namespace std;

Engine::Engine() : engineNumber("0000")
{
    horsepower = 0;
    torque = 0;
    capacity = 0;
    engineType = "Petrol";
}
Engine::Engine(string Enumber, int hp, int torque, int Ecap, string type) : engineNumber(Enumber)
{
    horsepower = hp;
    this->torque = torque;
    capacity = Ecap;
    engineType = type;
}

int Engine::getHP()
{
    return horsepower;
}
int Engine::getcapacity()
{
    return capacity;
}
string Engine::getEngineNumber()
{
    return engineNumber;
}

double Engine::performanceScore()
{
    return horsepower / capacity;
}
bool Engine::isPowerfulthan(const Engine &other)
{
    if (horsepower > other.horsepower)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int Engine::calculateAge(int BuyingYear, int CurrentYear)
{
    return CurrentYear - BuyingYear;
}
void Engine::displaySpecs() const
{
    cout << "\n===== Engine Detail =====\n";
    cout << "Engine Number: " << engineNumber << endl;
    cout << "Horse Power: " << horsepower << endl;
    cout << "Torque: " << torque << " N/M" << endl;
    cout << "Engine Type: " << engineType << endl;
    cout << "-----------------------------" << endl;
}

Car::Car() : engine(), location()
{
    brand = "";
    model = "";
    year = 0;
    price = 0.0;
    mileage = 0.0;

    PremiumCategory = false;
}
Car::Car(string brand, string model, int year, double price, float mileage, string transmission, Engine e, Location loc) : engine(e)
{

    location = loc;
    this->brand = brand;
    this->model = model;
    this->year = year;
    this->price = price;
    this->mileage = mileage;
    this->transmission = transmission;
    PremiumCategory = false;
}

Car::Car(const Car &car) : engine(car.engine)
{
    brand = car.brand;
    model = car.model;
    year = car.year;
    price = car.price;
    mileage = car.mileage;

    transmission = car.transmission;

    location = car.location;
    PremiumCategory = car.PremiumCategory;
}

string Car::getBrand()
{
    return brand;
}
double Car::getPrice()
{
    return price;
}
int Car::getYear()
{
    return year;
}
float Car::getmileage()
{
    return mileage;
}
string Car::getmodel()
{
    return model;
}
void Car::setMileage(float mil)
{
    mileage = mil;
}

void Car::displayCarDetails() const
{
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
    cout << "Price: " << price << endl;
    cout << "Mileage: " << mileage << endl;
    cout << "Premium Category: " << (PremiumCategory ? "Yes" : "No");
    engine.displaySpecs();
    location.Displaylocation();
}
bool Car::isPremium()
{
    if (price > 50000000)
    {
        PremiumCategory = true;
    }
    PremiumCategory = false;

    return PremiumCategory;
}
void Car::updatePrice()
{
    double newPrice;
    cout << "Enter New Price: ";
    cin >> newPrice;

    price = newPrice;
    cout << "Price Updated!" << endl;
}
void Car::CompareCarPrice(const Car &other)
{
    if (price > other.price)
    {
        cout << "It is Expensive" << endl;
    }
    else
    {
        cout << "It is Cheaper" << endl;
    }
}
Location::Location()
{
    city = "Unknown";
    area = "Unknown";
    province = "Unknown";
    country = "Unknown";
    zipcode = 0;
}
Location::Location(string country, string province, string city, string area, int zipcode)
{
    this->country = country;
    this->city = city;
    this->area = area;
    this->province = province;
    this->zipcode = zipcode;
}
// void Location::setCity(string city)
// {
//     this->city = city;
// }
// void Location::setArea(string area)
// {
//     this->area = area;
// }
// void Location::setProvince(string province)
// {
//     this->province = province;
// }
// void Location::setCountry(string country)
// {
//     this->country = country;
// }
// void Location::setZipCode(int zc)
// {
//     zipcode = zc;
// }
string Location::getCity()
{
    return city;
}
string Location::getArea()
{
    return area;
}
string Location::getProvince()
{
    return province;
}
string Location::getCountry()
{
    return country;
}
int Location::getZipCode()
{
    return zipcode;
}
void Location::Displaylocation() const
{
    cout << "\n====== Location Details ======\n";
    cout << "Area: " << area << endl;
    cout << "Zipcode: " << zipcode << endl;
    cout << "City: " << city << endl;
    cout << "Province: " << province << endl;
    cout << "Country: " << country << endl;
    cout << "\n-------------------------------\n";
}
void Location::updatelocation()
{
    int choice;
    cout << "\n===== UPDATE LOCATION =====\n";
    cout << "1. Update Area\n";
    cout << "2. Update City\n";
    cout << "3. Update Country\n";
    cout << "4. Update Province\n";
    cout << "5. Update Zipcode\n";
    cout << "Enter Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "Enter New Area: ";
        cin >> area;
        cout << "Area Updated Successfully!\n";
        break;

    case 2:
        cout << "Enter New City: ";
        cin >> city;
        cout << "City Updated Successfully!\n";
        break;

    case 3:
        cout << "Enter New Country: ";
        cin >> country;
        cout << "Country Updated Successfully!\n";
        break;

    case 4:
        cout << "Enter New Province: ";
        cin >> province;
        cout << "Province Updated Successfully!\n";
        break;
    case 5:
        cout << "Enter New Zipcode: ";
        cin >> zipcode;
        cout << "Zipcode Updated Successfully!\n";
    default:
        cout << "Invalid Choice!\n";
        break;
    }
}

bool Location::isSameCity(const Location &other)
{
    if (city == other.city)
    {
        return true;
    }
    return false;
}
bool Location::isSameProvince(const Location &other)
{
    if (province == other.province)
    {
        return true;
    }
    return false;
}
