#include <iostream>
#include "MarketPlace_System.h"
#include "User_Module.h"
using namespace std;

Listing::Listing() : listingId(00), car(), platformfee(0.04)
{
    seller = nullptr;
    askingPrice = 0.0;
    status = "N/A";
    postdate = "N/A";
}
Listing::Listing(int id, Car c, Seller *s, double price) : listingId(id), platformfee(0.04), car(c), seller(s)
{

    askingPrice = price;
    postdate = "Today";
    status = "Not Approved";
}
int Listing::getListingid() const
{
    return listingId;
}
string Listing::getStatus()
{
    return status;
}
double Listing::getaskPrice()
{
    return askingPrice;
}
Car Listing::getcar()
{
    return car;
}
void Listing::setPrice(double p)
{
    askingPrice = p;
}
double Listing::calculatePlatformCommission()
{
    return askingPrice * platformfee;
}
void Listing::setStatus(string newStatus)
{
    status = newStatus;
}
void Listing::updateStatus()
{
    if (status == "Approved")
    {
        status = "Remove";
    }
    else
    {
        status = "Approved";
    }
}

void Listing::displayListing() const
{
    cout << "ID: " << getListingid() << endl;
    car.displayCarDetails();
    seller->displaySeller();
    cout << "Asking Price: " << askingPrice << endl;
    cout << "Status: " << status << endl;
    cout << "PostDate: " << postdate << endl;
}
void Listing::setPostDate(string pd)
{
    postdate = pd;
}

int MarketPlace::totalUsers = 0;
int MarketPlace::totalListings = 0;
int MarketPlace::totalMessages = 0;
MarketPlace::MarketPlace() : messages()
{
    for (int i = 0; i < 100; i++)
    {
        user[i] = nullptr;
    }
    for (int i = 0; i < 200; i++)
    {
        listings[i] = nullptr;
    }
    for (int i = 0; i < 200; i++)
        messages[i] = nullptr;
}

void MarketPlace::getTotallisting()
{
    cout << "Total Lisiting: " << totalListings << endl;
}
void MarketPlace::gettotalusers()
{
    cout << "Total Users: " << totalUsers << endl;
}

void MarketPlace::addUser(User *u)
{
    if (totalUsers < 100)
    {
        user[totalUsers++] = u;
        cout << "User Added!" << endl;
    }
}

void MarketPlace::addListing(Listing *l)
{
    if (totalListings < 200)
    {
        listings[totalListings++] = l;
        cout << "Listing Added!" << endl;
    }
}
void MarketPlace::searchBybrand(string brand) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i]->getcar().getBrand() == brand)
        {
            listings[i]->displayListing();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "No Car Found of Brand " << brand << endl;
    }
}
void MarketPlace::filterByPrice(double start, double end) const
{
    for (int i = 0; i < totalListings; i++)
    {
        double price = listings[i]->getaskPrice();
        if (price >= start && price <= end)
        {
            listings[i]->displayListing();
        }
    }
}
void MarketPlace::displayAllListings() const
{
    if (totalListings == 0)
    {
        cout << "No listing!" << endl;
    }
    for (int i = 0; i < totalListings; i++)
    {
        cout << "\n------ Listing " << i + 1 << "------\n";
        listings[i]->displayListing();
    }
}
void MarketPlace::searchBymodel(string model) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i]->getcar().getmodel() == model)
        {
            listings[i]->displayListing();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "No Car Found of Model " << model << endl;
    }
}
void MarketPlace::searchByYear(int year) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i]->getcar().getYear() == year)
        {
            listings[i]->displayListing();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No Car Found of Year " << year << endl;
    }
}
Listing *MarketPlace::searchListingByid(int id) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i]->getListingid() == id)
        {
            return listings[i];
        }
    }
    return nullptr;
}
void MarketPlace::searchBymileage(float mileage) const
{
    bool found = false;
    for (int i = 0; i < totalListings; i++)
    {
        if (listings[i]->getcar().getmileage() == mileage)
        {
            listings[i]->displayListing();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "No Car Found of Mileage " << mileage << endl;
    }
}
void MarketPlace::addMessage(Message *m)
{
    if (totalMessages < 200)
        messages[totalMessages++] = m;
}
MarketPlace::~MarketPlace()
{
    for (int i = 0; i < totalListings; i++)
    {
        delete listings[i];
    }

    for (int i = 0; i < totalMessages; i++)
    {
        delete messages[i];
    }
    for (int i = 0; i < 100; i++)
    {
        delete user[i];
    }
}

int Message::totalmessages = 0;
Message ::Message() : messageId(0)
{

    senderId = 0;
    receiverId = 0;
    message = "N/A";
    isread = false;
}
Message::Message(int sid, int rid, string text) : messageId(++totalmessages)
{

    senderId = sid;
    receiverId = rid;
    message = text;
    isread = false;
}
string Message::getText()
{
    return message;
}
bool Message::getReadstatus()
{
    return isread;
}
void Message::send()
{
    cout << "Message Sent Successfully!" << endl;
}
void Message::Markread()
{
    isread = true;
    cout << "Message Marked as Read!" << endl;
}
void Message::displayMessage()
{
    cout << "\n------ MESSAGE DETAILS ------\n";
    cout << "Message ID: " << messageId << endl;
    cout << "Sender ID: " << senderId << endl;
    cout << "Receiver ID: " << receiverId << endl;
    cout << "Message: " << message << endl;
    cout << "Status: " << (isread ? "Read" : "Unread") << endl;
}