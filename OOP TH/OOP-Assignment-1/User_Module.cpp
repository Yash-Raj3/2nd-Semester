#include <iostream>
#include "User_Module.h"
#include "MarketPlace_System.h"
using namespace std;

User::User()
{
	userID = 0;
	name = "Unknown";
	email = "Unknown@gmail.com";
	phone = "0000-000000";
	city = "Unknown";
}
User::User(int id, string name, string email, string phone, string city)
{
	userID = id;
	this->name = name;
	this->email = email;
	this->phone = phone;
	this->city = city;
}
void User::setName(string name)
{
	this->name = name;
}
void User::setEmail(string email)
{
	this->email = email;
}
int User::getUserId()
{
	return userID;
}
string User::getName()
{
	return name;
}
string User::getEmail()
{
	return email;
}
void User::login()
{
	cout << name << " Logged In Successfully" << endl;
}
void User::logout()
{
	cout << name << " Logged Out Successfully" << endl;
}
void User::viewProfile() const
{
	cout << "=== USER DETAILS ===" << endl;
	cout << "User Id: " << userID << endl;
	cout << "Name: " << name << endl;
	cout << "Email: " << email << endl;
	cout << "Phone: " << phone << endl;
	cout << "City: " << city << endl;
}
void User::updateProfile()
{

	int choice;

	cout << "\n--- Update Profile ---\n";
	cout << "1. Update Name\n";
	cout << "2. Update Email\n";
	cout << "3. Update Phone\n";
	cout << "4. Update City\n";
	cout << "Enter Choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		cout << "Enter New Name: ";
		cin >> name;
		cout << "Name Updated Successfully!\n";
		break;

	case 2:
		cout << "Enter New Email: ";
		cin >> email;
		cout << "Email Updated Successfully!\n";
		break;

	case 3:
		cout << "Enter New Phone: ";
		cin >> phone;
		cout << "Phone Updated Successfully!\n";
		break;

	case 4:
		cout << "Enter New City: ";
		cin >> city;
		cout << "City Updated Successfully!\n";
		break;

	default:
		cout << "Invalid Choice!\n";
		break;
	}
}

Buyer::Buyer()
{
	favouriteCount = 0;
	budget = 0;
	preferedBrand = "";
	for (int i = 0; i < 30; i++)
	{
		favourites[i] = nullptr;
	}
}

Buyer::Buyer(User u, double Budget, string preferedbrand)
{
	user = u;
	budget = Budget;
	favouriteCount = 0;
	preferedBrand = preferedbrand;
	for (int i = 0; i < 30; i++)
	{
		favourites[i] = nullptr;
	}
}
double Buyer::getBudget()
{
	return budget;
}

int Buyer::getfavoriteCount()
{
	return favouriteCount;
}

void Buyer::setBudget(double budget)
{
	this->budget = budget;
}
void Buyer::saveFavorite(Listing *fav)
{
	if (favouriteCount < 30)
	{
		favourites[favouriteCount++] = fav;
		cout << "Listing Added to Favorites!\n";
	}
	else
	{
		cout << "Favorite List is Full!\n";
	}
}
void Buyer::removeFavorite(int index)
{
	if (index < 0 || index >= favouriteCount)
	{
		cout << "Invalid Index!\n";
		return;
	}

	for (int i = index; i < favouriteCount - 1; i++)
	{
		favourites[i] = favourites[i + 1];
	}

	favouriteCount--;
	cout << "Favorite Removed Successfully!\n";
}
void Buyer::displayFavorites()
{
	if (favouriteCount == 0)
	{
		cout << "No Favorites Added Yet!\n";
		return;
	}

	cout << "\n--- Favorite Listings ---\n";

	for (int i = 0; i < favouriteCount; i++)
	{
		cout << "\nFavorite " << i + 1 << ":\n";
		favourites[i]->displayListing();
	}
}
void Buyer::sendMessage(MarketPlace *marketplace)
{
	int rid;
	string text;
	cout << "Enter Reciever Id: ";
	cin >> rid;

	cout << "Enter Your Message: ";

	getline(cin, text);

	Message *m = new Message(user.getUserId(), rid, text);
	marketplace->addMessage(m);
	cout << "Message Sent Successfully\n";
}
int Buyer::getUserid()
{
	return user.getUserId();
}

int Seller::totalSeller = 0;

Seller::Seller()
{
	total_listing = 0;
	showroomName = "Unknown";
	rating = 0.0;
	totalSeller++;
	verified = false;
	for (int i = 0; i < 20; i++)
	{
		listings[i] = nullptr;
	}
}
Seller::Seller(User u, string showroomName)
{
	user = u;
	this->showroomName = showroomName;
	rating = 0.0;
	totalSeller++;
	verified = false;
	total_listing = 0;
	for (int i = 0; i < 20; i++)
	{
		listings[i] = nullptr;
	}
}

int Seller::getTotallisting()
{
	return total_listing;
}
void Seller::setRating(float r)
{
	if (r >= 0 && r <= 5)
	{
		rating = r;
		cout << "Rating Updated Successfully!\n";
	}
	else
	{
		cout << "Rating must be between 0 and 5!\n";
	}
}
void Seller::addlisting(int id, Car c, double price)
{
	if (total_listing < 20)
	{
		listings[total_listing++] = new Listing(id, c, this, price);
		cout << "Listing Added!" << endl;
	}
	else
	{
		cout << "Listing Limit Reached!" << endl;
	}
}
void Seller::updatelisting()
{
	int index;
	double newprice;
	cout << "Enter Index: ";
	cin >> index;
	if (index >= 0 && index < total_listing)
	{
		cout << "Enter New Price: ";
		cin >> newprice;
		listings[index]->setPrice(newprice);
		cout << "Price Updated Successfully!" << endl;
	}
	else
	{
		cout << "Invalid Index" << endl;
	}
}
void Seller::removelisting()
{

	int index;
	cout << "Enter Index: ";
	cin >> index;
	if (index >= 0 && index < total_listing)
	{
		for (int i = index; i < total_listing; i++)
		{
			listings[i] = listings[i + 1];
		}

		listings[total_listing - 1] = nullptr;
		total_listing--;
		cout << "Listing at Index " << index << " Removed" << endl;
	}
	else
	{
		cout << "Invalid Index!" << endl;
	}
}
void Seller::displaySellerListings() const
{
	if (total_listing == 0)
	{
		cout << "No listing Available!" << endl;
		return;
	}
	for (int i = 0; i < total_listing; i++)
	{
		if (listings[i] != nullptr)
			listings[i]->displayListing();
	}
}
void Seller::VerifSeller()
{
	if (rating >= 2.5)
	{
		verified = true;
	}
}
void Seller::displaySeller() const
{
	cout << "====== Seller Details ======" << endl;
	user.viewProfile();
	cout << "ShowRoom Name: " << showroomName << endl;
	cout << "Rating: " << rating << endl;
	cout << "Verified: " << (verified ? "Yes" : "No") << endl;
	cout << "Total Listing: " << total_listing << endl;
	for (int i = 0; i < total_listing; i++)
	{
		if (listings[i] != nullptr)
			listings[i]->displayListing();
	}
}

void Seller::displytotalsellers()
{
	cout << "Total: " << totalSeller << endl;
}
int Seller::getUserid()
{
	return user.getUserId();
}

int Admin::totalAdmins = 0;
Admin::Admin() : adminid(++totalAdmins)
{
	approvedCount = 0;
	removeCount = 0;
	adminlevel = 1;
}
Admin::Admin(User u, int level) : adminid(++totalAdmins)
{
	adminlevel = level;
	user = u;
	approvedCount = 0;
	removeCount = 0;
}
Admin::Admin(const Admin &other) : adminid(other.adminid)
{
	adminlevel = other.adminlevel;
	user = other.user;
	approvedCount = other.approvedCount;
	removeCount = other.removeCount;
	totalAdmins++;
}
void Admin::approvedlisting(Listing &l)
{
	l.updateStatus();
	approvedCount++;
	cout << "Approved Listing!" << endl;
}
void Admin::removeListing(Listing &l)
{
	l.updateStatus();
	removeCount++;
}
void Admin::generateReport() const
{
	cout << "\n----- Admin Report -----\n";
	cout << "Admin ID: " << adminid << endl;
	cout << "Admin Level: " << adminlevel << endl;
	cout << "Total Approved Listings: " << approvedCount << endl;
	cout << "Total Removed Listings: " << removeCount << endl;
}

void Admin::displayAdminPanel() const
{
	cout << "\n===== Admin Panel =====\n";
	cout << "Admin ID: " << adminid << endl;
	cout << "Level: " << adminlevel << endl;
}

void Admin::DisplayTotalAdmins()
{
	cout << "Total Admins: " << totalAdmins << endl;
}
Admin::~Admin()
{
	totalAdmins--;
}