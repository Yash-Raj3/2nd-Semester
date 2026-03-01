#ifndef UserModule_H
#define UserModule_H
#include <string>

using namespace std;
class Listing;
class Car;
class MarketPlace;
class User
{
private:
	int userID;
	string name;
	string email;
	string phone;
	string city;

public:
	User();
	User(int id, string name, string email, string phone, string city);
	void setName(string name);
	void setEmail(string email);
	int getUserId();
	string getName();
	string getEmail();
	void login();
	void logout();
	void viewProfile() const;
	void updateProfile();
};
class Buyer
{
private:
	User user;
	string preferedBrand;
	Listing *favourites[30];
	int favouriteCount;
	double budget;

public:
	Buyer();
	Buyer(User u, double Budget, string preferedbrand);
	double getBudget();
	int getfavoriteCount();
	void setBudget(double budget);
	int getUserid();
	void saveFavorite(Listing *fav);
	void removeFavorite(int index);
	void sendMessage(MarketPlace *marketplace);
	void displayFavorites();
};

class Seller
{
private:
	User user;
	Listing *listings[20];
	int total_listing;
	string showroomName;
	float rating;
	bool verified;
	static int totalSeller;

public:
	Seller();
	Seller(User u, string showroomName);

	int getTotallisting();
	void setRating(float r);
	void addlisting(int id, Car c, double price);
	void updatelisting();
	void removelisting();
	int getUserid();
	void VerifSeller();
	void displaySellerListings() const;
	void displaySeller() const;
	static void displytotalsellers();
};
class Admin
{
private:
	User user;
	const int adminid;
	int approvedCount;
	int adminlevel;
	int removeCount;
	static int totalAdmins;

public:
	Admin();
	Admin(User u, int level);
	Admin(const Admin &other);
	void approvedlisting(Listing &l);
	void removeListing(Listing &l);
	void generateReport() const;
	void displayAdminPanel() const;
	static void DisplayTotalAdmins();
	~Admin();
};

#endif
