#ifndef Market_H
#define Market_H
#include <string>
#include "Vehiclesystem.h"
using namespace std;
class User;
class Seller;

class Listing
{
	const int listingId;
	Car car;
	Seller *seller;
	double askingPrice;
	string status;
	string postdate;
	const int platformfee;

public:
	Listing();
	Listing(int id, Car c, Seller *s, double price);
	int getListingid() const;
	string getStatus();
	double getaskPrice();
	void setPostDate(string pd);
	Car getcar();
	void setStatus(string status);
	void setPrice(double p);
	void updateStatus();
	double calculatePlatformCommission();
	void displayListing() const;
};
class Message
{
private:
	const int messageId;
	int senderId;
	int receiverId;
	string message;
	bool isread;
	static int totalmessages;

public:
	Message();
	Message(int sid, int rid, string text);
	string getText();
	bool getReadstatus();
	void send();
	void Markread();
	void displayMessage();
};

class MarketPlace
{
private:
	User *user[100];
	Listing *listings[200];
	Message *messages[200];
	static int totalUsers;
	static int totalListings;
	static int totalMessages;

public:
	MarketPlace();
	static void getTotallisting();
	static void gettotalusers();
	void addUser(User *u);
	void addListing(Listing *l);
	void searchBybrand(string brand) const;
	void searchBymodel(string model) const;
	void searchByYear(int year) const;
	void searchBymileage(float mileage) const;
	void filterByPrice(double start, double end) const;
	Listing *searchListingByid(int id) const;
	void displayAllListings() const;
	void addMessage(Message *m);
	~MarketPlace();
};

#endif
