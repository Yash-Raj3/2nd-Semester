#include <iostream>
#include <string>
// Abstract & Interface classes
#include "Displayable.h"
#include "Searchable.h"
#include "Billable.h"
#include "PersonBase.h"

using namespace std;

class Listing;
class Seller;
class Buyer;
class MarketPlace;

// -------------------- Location Class--------------------
class Location
{
private:
    string city;
    string area;
    string province;
    string country;
    int zipcode;

public:
    Location() : city("Unknown"), area("Unknown"), province("Unknown"), country("Unknown"), zipcode(0) {}
    Location(string ctry, string prov, string c, string a, int z)
        : city(c), area(a), province(prov), country(ctry), zipcode(z) {}

    string getCity() const { return city; }
    string getArea() const { return area; }
    string getProvince() const { return province; }
    string getCountry() const { return country; }
    int getZipCode() const { return zipcode; }

    // Operator Overloading
    bool operator==(const Location &other) const
    {
        return city == other.city && area == other.area && zipcode == other.zipcode;
    }

    bool operator<(const Location &other) const
    {
        return zipcode < other.zipcode;
    }

    Location operator+(const Location &other) const
    {
        Location merged = *this;
        merged.area = other.area;
        return merged;
    }

    // Friend stream operators
    // Overloading '<<' so we can directly print our custom objects using cout.
    friend ostream &operator<<(ostream &out, const Location &loc);
    // Overloading '>>' to allow reading directly from input stream using cin.
    friend istream &operator>>(istream &in, Location &loc);
};

ostream &operator<<(ostream &out, const Location &loc)
{
    out << loc.area << ", " << loc.city << ", " << loc.province << ", " << loc.country << " - " << loc.zipcode;
    return out;
}

istream &operator>>(istream &in, Location &loc)
{
    in >> loc.city >> loc.area >> loc.province >> loc.country >> loc.zipcode;
    return in;
}

// -------------------- Engine Class--------------------
class Engine
{
private:
    string engineNumber;
    int horsePower;
    int torque;
    int capacity;
    string engineType;

public:
    Engine() : engineNumber("0000"), horsePower(0), torque(0), capacity(1000), engineType("Petrol") {}
    Engine(string eNo, int hp, int tq, int cap, string type)
        : engineNumber(eNo), horsePower(hp), torque(tq), capacity(cap), engineType(type) {}

    int getHP() const { return horsePower; }
    int getCapacity() const { return capacity; }

    double performanceScore() const
    {
        return (double)(horsePower + torque) / capacity;
    }

    // Operator Overloading
    bool operator>(const Engine &other) const
    {
        return horsePower > other.horsePower;
    }

    bool operator==(const Engine &other) const
    {
        return engineNumber == other.engineNumber;
    }

    Engine operator+(const Engine &other) const
    {
        Engine blended = *this;
        blended.horsePower += other.horsePower / 2;
        blended.torque += other.torque / 2;
        return blended;
    }

    friend ostream &operator<<(ostream &out, const Engine &e);
};

ostream &operator<<(ostream &out, const Engine &e)
{
    out << "Engine[" << e.engineNumber << "] " << e.horsePower << "HP, " << e.torque << "Nm, " << e.capacity << "cc, " << e.engineType;
    return out;
}

// -------------------- Vehicle Hierarchy --------------------
class Vehicle : public Displayable, public Searchable
{
protected:
    string regNo;
    string brand;
    string model;
    int year;
    double basePrice;
    float mileage;
    Engine engine;
    Location location;

public:
    Vehicle()
        : regNo("N/A"), brand("N/A"), model("N/A"), year(0), basePrice(0), mileage(0), engine(), location() {}

    Vehicle(string r, string b, string m, int y, double p, float mil, Engine e, Location loc)
        : regNo(r), brand(b), model(m), year(y), basePrice(p), mileage(mil), engine(e), location(loc) {}
    /*  This forces every child class
     (like Car or Bike) to write its own logic for road tax,
     since the rate is different for each.*/

    virtual double roadTax() const = 0;
    virtual string getType() const = 0;
    virtual Vehicle *clone() const = 0;

    string getBrand() const { return brand; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getPrice() const { return basePrice; }
    float getMileage() const { return mileage; }

    // Operator Overloading
    bool operator<(const Vehicle &other) const
    {
        return basePrice < other.basePrice;
    }

    bool operator==(const Vehicle &other) const
    {
        return regNo == other.regNo;
    }

    // searchable behavior for all vehicle types.
    bool matchesKeyword(const string &keyword) const
    {
        return brand == keyword || model == keyword || regNo == keyword;
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle
{
private:
    bool hybrid;

public:
    Car() : Vehicle(), hybrid(false) {}
    Car(string r, string b, string m, int y, double p, float mil, Engine e, Location loc, bool h)
        : Vehicle(r, b, m, y, p, mil, e, loc), hybrid(h) {}

    double roadTax() const
    {
        return basePrice * 0.03;
    }

    string getType() const
    {
        return "Car";
    }

    Vehicle *clone() const
    {
        return new Car(*this);
    }

    // Polymorphic overriding
    void displayDetails() const
    {
        cout << "\n[Car] " << brand << " " << model << " (" << year << ")\n";
        cout << "Reg#: " << regNo << " | Price: " << basePrice << " | Mileage: " << mileage << "\n";
        cout << "Hybrid: " << (hybrid ? "Yes" : "No") << "\n";
        cout << engine << "\n";
        cout << "Location: " << location << "\n";
    }
};

class Bike : public Vehicle
{
private:
    bool sportsEdition;

public:
    Bike() : Vehicle(), sportsEdition(false) {}
    Bike(string r, string b, string m, int y, double p, float mil, Engine e, Location loc, bool s)
        : Vehicle(r, b, m, y, p, mil, e, loc), sportsEdition(s) {}

    double roadTax() const
    {
        return basePrice * 0.015;
    }

    string getType() const
    {
        return "Bike";
    }

    Vehicle *clone() const
    {
        return new Bike(*this);
    }

    // Polymorphic overriding
    void displayDetails() const
    {
        cout << "\n[Bike] " << brand << " " << model << " (" << year << ")\n";
        cout << "Reg#: " << regNo << " | Price: " << basePrice << " | Mileage: " << mileage << "\n";
        cout << "Sports Edition: " << (sportsEdition ? "Yes" : "No") << "\n";
        cout << engine << "\n";
        cout << "Location: " << location << "\n";
    }
};

class Truck : public Vehicle
{
private:
    int loadCapacityKg;

public:
    Truck() : Vehicle(), loadCapacityKg(0) {}
    Truck(string r, string b, string m, int y, double p, float mil, Engine e, Location loc, int loadKg)
        : Vehicle(r, b, m, y, p, mil, e, loc), loadCapacityKg(loadKg) {}

    double roadTax() const
    {
        return basePrice * 0.04;
    }

    string getType() const
    {
        return "Truck";
    }

    Vehicle *clone() const
    {
        return new Truck(*this);
    }

    // Polymorphic overriding
    void displayDetails() const
    {
        cout << "\n[Truck] " << brand << " " << model << " (" << year << ")\n";
        cout << "Reg#: " << regNo << " | Price: " << basePrice << " | Mileage: " << mileage << "\n";
        cout << "Load Capacity: " << loadCapacityKg << " KG\n";
        cout << engine << "\n";
        cout << "Location: " << location << "\n";
    }
};

// -------------------- User Hierarchy --------------------
class User : public PersonBase, public Displayable
{
private:
    string email;
    string phone;
    string city;

protected:
    bool loggedIn;

public:
    User() : PersonBase(), email("Unknown@gmail.com"), phone("0000-0000000"), city("Unknown"), loggedIn(false) {}
    User(int id, string n, string e, string p, string c)
        : PersonBase(id, n), email(e), phone(p), city(c), loggedIn(false) {}

    int getUserID() const { return userID; }
    string getName() const { return name; }
    string getCity() const { return city; }

    void login()
    {
        loggedIn = true;
        cout << name << " logged in.\n";
    }

    void logout()
    {
        loggedIn = false;
        cout << name << " logged out.\n";
    }

    // Function overriding from abstract class
    void viewProfile() const
    {
        cout << "ID: " << userID << " | Name: " << name << " | Email: " << email;
        cout << " | Phone: " << phone << " | City: " << city << "\n";
    }

    // Function overriding from abstract class
    void updateProfile()
    {
        cout << "\nUpdating basic profile for " << name << "\n";
        city = city + "-Updated";
    }

    // Function overriding from Displayable
    void displayDetails() const
    {
        viewProfile();
    }

    // Operator overloading
    bool operator==(const User &other) const
    {
        return userID == other.userID;
    }

    bool operator<(const User &other) const
    {
        return userID < other.userID;
    }

    // Friend function and friend class to justify controlled private access.
    friend bool canExchangePrivateContact(const Buyer &b, const Seller &s);
    friend class AuthInspector;

    virtual ~User() {}
};

class Buyer : public User
{
private:
    double budget;
    string preferredBrand;
    Listing *favorites[30];
    int favoriteCount;

public:
    Buyer() : User(), budget(0), preferredBrand("N/A"), favoriteCount(0)
    {
        for (int i = 0; i < 30; i++)
            favorites[i] = nullptr;
    }

    Buyer(int id, string n, string e, string p, string c, double b, string pref)
        : User(id, n, e, p, c), budget(b), preferredBrand(pref), favoriteCount(0)
    {
        for (int i = 0; i < 30; i++)
            favorites[i] = nullptr;
    }

    double getBudget() const { return budget; }

    /*Function overloading
      This is done to set the preference
      of a buyer to a certain brand*/
    void setPreference(const string &brand)
    {
        preferredBrand = brand;
    }

    void setPreference(const string &brand, double maxBudget)
    {
        preferredBrand = brand;
        budget = maxBudget;
    }

    void addFavorite(Listing *l);

    // Operator overloading
    Buyer operator+(double extraBudget) const
    {
        Buyer temp = *this;
        temp.budget += extraBudget;
        return temp;
    }

    void displayDetails() const
    {
        cout << "[Buyer] ";
        User::displayDetails();
        cout << "Budget: " << budget << " | Preferred Brand: " << preferredBrand << "\n";
    }
};

class Admin : public User
{
protected:
    int adminLevel;
    int approvedCount;
    int removedCount;

public:
    Admin() : User(), adminLevel(1), approvedCount(0), removedCount(0) {}
    Admin(int id, string n, string e, string p, string c, int level)
        : User(id, n, e, p, c), adminLevel(level), approvedCount(0), removedCount(0) {}

    void approveListing(Listing &l);
    void removeListing(Listing &l);

    void displayDetails() const
    {
        cout << "[Admin] ";
        User::displayDetails();
        cout << "Admin Level: " << adminLevel << " | Approved: " << approvedCount << " | Removed: " << removedCount << "\n";
    }
};

class SuperAdmin : public Admin
{
private:
    bool systemAccess;

public:
    SuperAdmin() : Admin(), systemAccess(true) {}
    SuperAdmin(int id, string n, string e, string p, string c)
        : Admin(id, n, e, p, c, 5), systemAccess(true) {}

    void displayDetails() const
    {
        cout << "[SuperAdmin] ";
        User::displayDetails();
        cout << "System Access: " << (systemAccess ? "Full" : "Limited") << "\n";
    }
};

class Moderator : public Admin
{
private:
    string section;

public:
    Moderator() : Admin(), section("Listings") {}
    Moderator(int id, string n, string e, string p, string c, string sec)
        : Admin(id, n, e, p, c, 2), section(sec) {}

    void displayDetails() const
    {
        cout << "[Moderator] ";
        User::displayDetails();
        cout << "Section: " << section << "\n";
    }
};

class Seller : public User
{
private:
    string showroomName;
    float rating;
    bool verified;
    Listing *inventory[20];
    int totalListings;

public:
    Seller() : User(), showroomName("Unknown"), rating(0), verified(false), totalListings(0)
    {
        for (int i = 0; i < 20; i++)
            inventory[i] = nullptr;
    }

    Seller(int id, string n, string e, string p, string c, string showroom)
        : User(id, n, e, p, c), showroomName(showroom), rating(0), verified(false), totalListings(0)
    {
        for (int i = 0; i < 20; i++)
            inventory[i] = nullptr;
    }

    void setRating(float r)
    {
        if (r >= 0 && r <= 5)
        {
            rating = r;
            verified = (rating >= 2.5);
        }
    }

    int getTotalListings() const { return totalListings; }

    void addListing(int listingId, Vehicle *v, double ask, MarketPlace *mp);

    void displayInventory() const;

    void displayDetails() const
    {
        cout << "[Seller] ";
        User::displayDetails();
        cout << "Showroom: " << showroomName << " | Rating: " << rating;
        cout << " | Verified: " << (verified ? "Yes" : "No") << " | Listings: " << totalListings << "\n";
    }
};

// -------------------- Message and Listing --------------------
class Message : public Displayable
{
private:
    const int messageID;
    int senderID;
    int receiverID;
    string text;
    bool isRead;
    static int totalMessages;

public:
    Message() : messageID(++totalMessages), senderID(0), receiverID(0), text("N/A"), isRead(false) {}
    Message(int sid, int rid, string msg)
        : messageID(++totalMessages), senderID(sid), receiverID(rid), text(msg), isRead(false) {}

    void markRead() { isRead = true; }

    bool operator==(const Message &other) const
    {
        return messageID == other.messageID;
    }

    bool operator<(const Message &other) const
    {
        return messageID < other.messageID;
    }

    void displayDetails() const
    {
        cout << "Message#" << messageID << " | Sender: " << senderID << " | Receiver: " << receiverID;
        cout << " | Text: " << text << " | Status: " << (isRead ? "Read" : "Unread") << "\n";
    }
};

int Message::totalMessages = 0;

class AuditService;

class Listing : public Displayable, public Billable
{
private:
    const int listingID;
    Vehicle *vehicle;
    Seller *seller;
    double askingPrice;
    string status;
    string postDate;
    const double platformFeeRate;

public:
    Listing()
        : listingID(0), vehicle(nullptr), seller(nullptr), askingPrice(0), status("Draft"), postDate("Today"), platformFeeRate(0.04) {}

    Listing(int id, Vehicle *v, Seller *s, double ask)
        : listingID(id), vehicle(v), seller(s), askingPrice(ask), status("Pending"), postDate("Today"), platformFeeRate(0.04) {}
    /* Copy constructor is necessary here to perform
      a deep copy of the Vehicle pointer,
      preventing memory leak
    */
    Listing(const Listing &other)
        : listingID(other.listingID),
          vehicle(other.vehicle != nullptr ? other.vehicle->clone() : nullptr),
          seller(other.seller),
          askingPrice(other.askingPrice),
          status(other.status),
          postDate(other.postDate),
          platformFeeRate(other.platformFeeRate) {}

    Listing &operator=(const Listing &other)
    {
        if (this != &other)
        {
            delete vehicle;
            vehicle = (other.vehicle != nullptr) ? other.vehicle->clone() : nullptr;
            seller = other.seller;
            askingPrice = other.askingPrice;
            status = other.status;
            postDate = other.postDate;
        }
        return *this;
    }

    int getListingID() const { return listingID; }
    double getAskPrice() const { return askingPrice; }
    string getStatus() const { return status; }
    Vehicle *getVehicle() const { return vehicle; }

    void setStatus(const string &st) { status = st; }
    void setAskPrice(double p) { askingPrice = p; }

    /* Billable override
     Used to calculate the final amount
    */
    double finalAmount() const
    {
        return askingPrice + askingPrice * platformFeeRate;
    }

    // Operator Overloading
    bool operator==(const Listing &other) const
    {
        return listingID == other.listingID;
    }

    bool operator<(const Listing &other) const
    {
        return askingPrice < other.askingPrice;
    }
    /* This increases the price
      of a listing just by using the '+'*/

    Listing operator+(double increment) const
    {
        Listing temp = *this;
        temp.askingPrice += increment;
        return temp;
    }

    void displayDetails() const
    {
        cout << "\n------ Listing ------\n";
        cout << "Listing ID: " << listingID << " | Ask Price: " << askingPrice;
        cout << " | Final Amount: " << finalAmount() << " | Status: " << status << " | Post Date: " << postDate << "\n";
        if (seller != nullptr)
            cout << "Seller: " << seller->getName() << "\n";
        if (vehicle != nullptr)
            vehicle->displayDetails();
    }

    // Friend class + friend operators
    friend class AuditService;
    friend ostream &operator<<(ostream &out, const Listing &l);
    friend istream &operator>>(istream &in, Listing &l);

    ~Listing()
    {
        delete vehicle;
    }
};

ostream &operator<<(ostream &out, const Listing &l)
{
    out << "Listing(" << l.listingID << ") Price=" << l.askingPrice << " Status=" << l.status;
    return out;
}

istream &operator>>(istream &in, Listing &l)
{
    in >> l.askingPrice >> l.status;
    return in;
}

class AuditService
{
public:
    static void showInternalListingData(const Listing &l)
    {
        cout << "[Audit] Listing#" << l.listingID << " | Fee Rate: " << l.platformFeeRate << " | Ask: " << l.askingPrice << "\n";
    }
};

// -------------------- Marketplace --------------------
class MarketPlace : public Displayable
{
private:
    User *users[100];
    Listing *listings[200];
    Message *messages[200];

    int totalUsers;
    int totalListings;
    int totalMessages;

public:
    MarketPlace() : totalUsers(0), totalListings(0), totalMessages(0)
    {
        for (int i = 0; i < 100; i++)
            users[i] = nullptr;
        for (int i = 0; i < 200; i++)
        {
            listings[i] = nullptr;
            messages[i] = nullptr;
        }
    }

    void addUser(User *u)
    {
        if (totalUsers < 100)
            users[totalUsers++] = u;
    }

    void addListing(Listing *l)
    {
        if (totalListings < 200)
            listings[totalListings++] = l;
    }

    void addMessage(Message *m)
    {
        if (totalMessages < 200)
            messages[totalMessages++] = m;
    }

    Listing *searchByID(int id) const
    {
        for (int i = 0; i < totalListings; i++)
        {
            if (listings[i] != nullptr && listings[i]->getListingID() == id)
                return listings[i];
        }
        return nullptr;
    }

    // Function Overloading
    void search(const string &brand) const
    {
        cout << "\nSearch by brand: " << brand << "\n";
        bool found = false;
        for (int i = 0; i < totalListings; i++)
        {
            Vehicle *v = listings[i]->getVehicle();
            if (v != nullptr && v->getBrand() == brand)
            {
                listings[i]->displayDetails();
                found = true;
            }
        }
        if (!found)
            cout << "No listing found.\n";
    }
    /*Function Overloading: Gives us multiple ways
    to search (by year, by brand, etc.) using the
    exact same function name for convenience.*/

    void search(const string &brand, const string &model) const
    {
        cout << "\nSearch by brand+model: " << brand << " " << model << "\n";
        bool found = false;
        for (int i = 0; i < totalListings; i++)
        {
            Vehicle *v = listings[i]->getVehicle();
            if (v != nullptr && v->getBrand() == brand && v->getModel() == model)
            {
                listings[i]->displayDetails();
                found = true;
            }
        }
        if (!found)
            cout << "No listing found.\n";
    }

    void search(int startYear, int endYear) const
    {
        cout << "\nSearch by year range: " << startYear << "-" << endYear << "\n";
        for (int i = 0; i < totalListings; i++)
        {
            Vehicle *v = listings[i]->getVehicle();
            if (v != nullptr && v->getYear() >= startYear && v->getYear() <= endYear)
            {
                listings[i]->displayDetails();
            }
        }
    }

    void search(double minPrice, double maxPrice) const
    {
        cout << "\nSearch by price range: " << minPrice << " - " << maxPrice << "\n";
        for (int i = 0; i < totalListings; i++)
        {
            double p = listings[i]->getAskPrice();
            if (p >= minPrice && p <= maxPrice)
                listings[i]->displayDetails();
        }
    }

    // Operator Overloading

    MarketPlace &operator+=(User *u)
    {
        addUser(u);
        return *this;
    }

    MarketPlace &operator+=(Listing *l)
    {
        addListing(l);
        return *this;
    }

    void displayDetails() const
    {
        cout << "\n===== Marketplace Summary =====\n";
        cout << "Users: " << totalUsers << " | Listings: " << totalListings << " | Messages: " << totalMessages << "\n";
    }

    ~MarketPlace()
    {
        for (int i = 0; i < totalListings; i++)
            delete listings[i];

        for (int i = 0; i < totalMessages; i++)
            delete messages[i];

        for (int i = 0; i < totalUsers; i++)
            delete users[i];
    }
};

// -------------------- Deferred Methods --------------------
void Buyer::addFavorite(Listing *l)
{
    if (favoriteCount < 30)
    {
        favorites[favoriteCount++] = l;
        cout << name << " saved listing " << l->getListingID() << " to favorites.\n";
    }
}

void Seller::addListing(int listingId, Vehicle *v, double ask, MarketPlace *mp)
{
    if (totalListings < 20)
    {
        Listing *newListing = new Listing(listingId, v, this, ask);
        inventory[totalListings++] = newListing;
        mp->addListing(newListing);
        cout << showroomName << " added listing " << listingId << "\n";
    }
    else
    {
        cout << "Listing limit reached for seller.\n";
        delete v;
    }
}

void Seller::displayInventory() const
{
    cout << "\nInventory of " << showroomName << "\n";
    if (totalListings == 0)
    {
        cout << "No listings available.\n";
        return;
    }

    for (int i = 0; i < totalListings; i++)
        inventory[i]->displayDetails();
}

void Admin::approveListing(Listing &l)
{
    l.setStatus("Approved");
    approvedCount++;
}

void Admin::removeListing(Listing &l)
{
    l.setStatus("Removed");
    removedCount++;
}

/* Friend Function: This needs to be a friend because
 it needs to peek into the private variables (like 'loggedIn')
of both Buyer and Seller at the same time.
*/
bool canExchangePrivateContact(const Buyer &b, const Seller &s)
{
    return b.loggedIn && s.loggedIn && b.city == s.city;
}

class AuthInspector
{
public:
    static void inspect(const User &u)
    {
        cout << "[AuthInspector] User " << u.name << " login state: " << (u.loggedIn ? "Online" : "Offline") << "\n";
    }
};

// -------------------- Main --------------------
int main()
{
    MarketPlace pakWheels;

    Seller *seller1 = new Seller(1, "Ali", "ali@gmail.com", "03008888888", "Karachi", "Ali Motors");
    Buyer *buyer1 = new Buyer(2, "Ahmed", "ahmed@gmail.com", "03111237897", "Karachi", 5000000, "Toyota");
    Admin *admin1 = new Admin(3, "Sara", "sara@gmail.com", "03221239876", "Lahore", 2);
    SuperAdmin *super1 = new SuperAdmin(4, "Hassan", "hassan@gmail.com", "03334567897", "Islamabad");
    Moderator *mod1 = new Moderator(5, "Mina", "mina@gmail.com", "03446574321", "Karachi", "Vehicle Moderation");

    pakWheels += seller1;
    pakWheels += buyer1;
    pakWheels += admin1;
    pakWheels += super1;
    pakWheels += mod1;

    seller1->login();
    buyer1->login();
    AuthInspector::inspect(*seller1);

    Engine e1("E123", 180, 250, 2000, "Petrol");
    Engine e2("E999", 100, 120, 1000, "Petrol");
    Engine e3 = e1 + e2;

    Location loc1("Pakistan", "Sindh", "Karachi", "Gulshan", 75300);
    Location loc2("Pakistan", "Punjab", "Lahore", "Johar Town", 54000);

    // overloaded stream extraction
    Location loc3;
    cout << "\nEnter Location details (City Area Province Country Zipcode): ";
    cin >> loc3;

    seller1->addListing(101, new Car("KHI-101", "Toyota", "Corolla", 2020, 4500000, 20000, e1, loc1, false), 4700000, &pakWheels);
    seller1->addListing(102, new Bike("KHI-404", "Honda", "CB150F", 2022, 450000, 9000, e2, loc2, true), 470000, &pakWheels);
    seller1->addListing(103, new Truck("ISB-777", "Hino", "500 Series", 2019, 8000000, 50000, e3, loc3, 7000), 8200000, &pakWheels);

    // Search Overloading
    pakWheels.search("Toyota");
    pakWheels.search("Honda", "CB150F");
    pakWheels.search(2018, 2023);
    pakWheels.search(400000.0, 5000000.0);

    Listing *found = pakWheels.searchByID(101);
    if (found != nullptr)
    {
        buyer1->addFavorite(found);
        admin1->approveListing(*found);
        AuditService::showInternalListingData(*found);

        Listing updated = *found + 200000;
        cout << "\nAfter + operator on Listing: " << updated << "\n";

        cout << "\nEnter updated Listing details (Price Status): ";
        cin >> updated;
        cout << "After >> operator on Listing: " << updated << "\n";
    }

    // Polymorphism through base class pointer array.
    Displayable *dashboard[4];
    dashboard[0] = seller1;
    dashboard[1] = buyer1;
    dashboard[2] = admin1;
    dashboard[3] = super1;

    cout << "\n=== User Dashboard ===\n";
    for (int i = 0; i < 4; i++)
        dashboard[i]->displayDetails();

    // Polymorphism using Vehicle base class pointers.
    Vehicle *sampleFleet[3];
    sampleFleet[0] = new Car("TMP-1", "Suzuki", "Swift", 2021, 3200000, 14000, e2, loc1, false);
    sampleFleet[1] = new Bike("TMP-2", "Yamaha", "YBR", 2020, 350000, 19000, e2, loc2, false);
    sampleFleet[2] = new Truck("TMP-3", "FAW", "Carrier", 2018, 6000000, 60000, e3, loc3, 5000);

    cout << "\n=== Vehicle Dashboard ===\n";
    for (int i = 0; i < 3; i++)
    {
        sampleFleet[i]->displayDetails();
        cout << "Road Tax: " << sampleFleet[i]->roadTax() << "\n";
        delete sampleFleet[i];
    }

    // Friend Function
    cout << "\nCan Buyer and Seller exchange private contact? "
         << (canExchangePrivateContact(*buyer1, *seller1) ? "Yes" : "No") << "\n";

    // Message
    Message *m1 = new Message(buyer1->getUserID(), seller1->getUserID(), "Is Corolla available?");
    m1->displayDetails();
    pakWheels.addMessage(m1);

    // Operator Overloading
    cout << "\nEngine 1 > Engine 2 ? " << (e1 > e2 ? "True" : "False") << "\n";
    cout << "Location 1 == Location 2 ? " << (loc1 == loc2 ? "True" : "False") << "\n";
    cout << "Merged Location (loc1 + loc2): " << (loc1 + loc2) << "\n";

    Buyer upgradedBuyer = (*buyer1) + 1000000;
    cout << "\nBuyer after + budget operator:\n";
    upgradedBuyer.displayDetails();

    seller1->displayInventory();
    pakWheels.displayDetails();

    return 0;
}