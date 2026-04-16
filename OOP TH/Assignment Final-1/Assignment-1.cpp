
#include <iostream>
using namespace std;

class MarketPlace; // Forward Declaration
class Seller;

/* I have used default and paramerterized constructor in every class to ensure if user
does not give info about that class then it will not intialize with garbage values and
if user gives the correct info, it will directly assign to the object attribute.*/

//---------------Location Class------------------
class Location
{
private:
    string city;
    string area;
    string province;
    string country;
    int zipcode;

public:
    Location() // Default constructor initializes objects with safe default values.
    {
        city = "Unknown";
        area = "Unknown";
        province = "Unknown";
        country = "Unknown";
        zipcode = 0;
    }
    // Parameterized constructor ensures object is created with valid data.
    Location(string country, string province, string city, string area, int zipcode)
    {
        this->country = country;
        this->city = city;
        this->area = area;
        this->province = province;
        this->zipcode = zipcode;
    }

    string getCity()
    {
        return city;
    }
    string getArea()
    {
        return area;
    }
    string getProvince()
    {
        return province;
    }
    string getCountry()
    {
        return country;
    }
    int getZipCode()
    {
        return zipcode;
    }
    void Displaylocation() const
    {
        cout << "\n====== Location Details ======\n";
        cout << "Area: " << area << endl;
        cout << "Zipcode: " << zipcode << endl;
        cout << "City: " << city << endl;
        cout << "Province: " << province << endl;
        cout << "Country: " << country << endl;
        cout << "\n-------------------------------\n";
    }
    void updatelocation()
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

    bool isSameCity(const Location &other)
    {
        if (city == other.city)
        {
            return true;
        }
        return false;
    }
    bool isSameProvince(const Location &other)
    {
        if (province == other.province)
        {
            return true;
        }
        return false;
    }
};
//--------------------Engine Class------------------
class Engine
{
private:
    const string engineNumber;
    int horsepower;
    int torque;
    int capacity;
    string engineType;

public:
    Engine() : engineNumber("0000") // Default constructor initializes objects with safe default values.
    {
        horsepower = 0;
        torque = 0;
        capacity = 0;
        engineType = "Petrol";
    }
    // Parameterized constructor ensures object is created with valid data.
    Engine(string Enumber, int hp, int torque, int Ecap, string type) : engineNumber(Enumber)
    {
        horsepower = hp;
        this->torque = torque;
        capacity = Ecap;
        engineType = type;
    }

    int getHP()
    {
        return horsepower;
    }
    int getcapacity()
    {
        return capacity;
    }
    string getEngineNumber()
    {
        return engineNumber;
    }

    double performanceScore()
    {
        return (double)horsepower / capacity;
    }
    bool isPowerfulthan(const Engine &other)
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
    int calculateAge(int BuyingYear, int CurrentYear)
    {
        return CurrentYear - BuyingYear;
    }
    void displaySpecs() const
    {
        cout << "\n===== Engine Detail =====\n";
        cout << "Engine Number: " << engineNumber << endl;
        cout << "Horse Power: " << horsepower << endl;
        cout << "Torque: " << torque << " N/M" << endl;
        cout << "Engine Type: " << engineType << endl;
        cout << "-----------------------------" << endl;
    }
};
//-----------------------Car Class------------------------------
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
    Car() : engine(), location() // Default constructor initializes objects with safe default values.
    {
        brand = "";
        model = "";
        year = 0;
        price = 0.0;
        mileage = 0.0;

        PremiumCategory = false;
    }
    // Parameterized constructor ensures object is created with valid data.
    Car(string brand, string model, int year, double price, float mileage, string transmission, Engine e, Location loc) : engine(e)
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
    /*Copy constructor ensures correct duplication of objects and prevents
     shallow copy issues when objects contain pointers or composed objects.*/
    Car(const Car &car) : engine(car.engine)
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

    string getBrand() const
    {
        return brand;
    }
    double getPrice()
    {
        return price;
    }
    int getYear()
    {
        return year;
    }
    float getmileage()
    {
        return mileage;
    }
    string getmodel()
    {
        return model;
    }
    void setMileage(float mil)
    {
        mileage = mil;
    }

    void displayCarDetails() const
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
    bool isPremium()
    {
        return price > 5000000;
    }
    void updatePrice()
    {
        double newPrice;
        cout << "Enter New Price: ";
        cin >> newPrice;

        price = newPrice;
        cout << "Price Updated!" << endl;
    }
    void CompareCarPrice(const Car &other)
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
};
//------------------------------User Class-------------------------
class User
{
private:
    int userID;
    string name;
    string email;
    string phone;
    string city;

public:
    User() // Default constructor initializes objects with safe default values.
    {
        userID = 0;
        name = "Unknown";
        email = "Unknown@gmail.com";
        phone = "0000-000000";
        city = "Unknown";
    }
    // Parameterized constructor ensures object is created with valid data.
    User(int id, string name, string email, string phone, string city)
    {
        userID = id;
        this->name = name;
        this->email = email;
        this->phone = phone;
        this->city = city;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setEmail(string email)
    {
        this->email = email;
    }
    int getUserId()
    {
        return userID;
    }
    string getName()
    {
        return name;
    }
    string getEmail()
    {
        return email;
    }
    void login()
    {
        cout << name << " Logged In Successfully" << endl;
    }
    void logout()
    {
        cout << name << " Logged Out Successfully" << endl;
    }
    void viewProfile() const
    {

        cout << "User Id: " << userID << endl;
        cout << "Name: " << name << endl;
        cout << "Email: " << email << endl;
        cout << "Phone: " << phone << endl;
        cout << "City: " << city << endl;
    }
    void updateProfile()
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
};
//---------------------------Message Class---------------------
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
    Message() : messageId(0) // Default constructor initializes objects with safe default values.
    {

        senderId = 0;
        receiverId = 0;
        message = "N/A";
        isread = false;
    }
    // Parameterized constructor ensures object is created with valid data.
    Message(int sid, int rid, string text) : messageId(++totalmessages)
    {

        senderId = sid;
        receiverId = rid;
        message = text;
        isread = false;
    }
    string getText()
    {
        return message;
    }
    bool getReadstatus()
    {
        return isread;
    }
    void send()
    {
        cout << "Message Sent Successfully!" << endl;
    }
    void Markread()
    {
        isread = true;
        cout << "Message Marked as Read!" << endl;
    }
    void displayMessage()
    {
        cout << "\n------ MESSAGE DETAILS ------\n";
        cout << "Message ID: " << messageId << endl;
        cout << "Sender ID: " << senderId << endl;
        cout << "Receiver ID: " << receiverId << endl;
        cout << "Message: " << message << endl;
        cout << "Status: " << (isread ? "Read" : "Unread") << endl;
    }
};

int Message::totalmessages = 0;
//---------------Listing Class-------------------
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
    Listing() : listingId(00), car(), platformfee(0.04) // Default constructor initializes objects with safe default values.
    {
        seller = nullptr;
        askingPrice = 0.0;
        status = "N/A";
        postdate = "N/A";
    }
    // Parameterized constructor ensures object is created with valid data.
    Listing(int id, Car c, Seller *s, double price) : listingId(id), platformfee(0.04), car(c), seller(s)
    {

        askingPrice = price;
        postdate = "Today";
        status = "Not Approved";
    }
    int getListingid() const
    {
        return listingId;
    }
    string getStatus()
    {
        return status;
    }
    double getaskPrice()
    {
        return askingPrice;
    }
    Car getcar()
    {
        return car;
    }
    void setPrice(double p)
    {
        askingPrice = p;
    }
    double calculatePlatformCommission()
    {
        return askingPrice * platformfee;
    }
    void setStatus(string newStatus)
    {
        status = newStatus;
    }
    void updateStatus()
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

    void displayListing() const;

    void setPostDate(string pd)
    {
        postdate = pd;
    }
};
//------------------Seller Class---------------------
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
    Seller() // Default constructor initializes objects with safe default values.
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
    // Parameterized constructor ensures object is created with valid data.
    Seller(User u, string showroomName)
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

    int getTotallisting()
    {
        return total_listing;
    }
    void setRating(float r)
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
    void addlisting(int id, Car c, double price, MarketPlace *mp);

    void updatelisting()
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
    void removelisting()
    {

        int index;
        cout << "Enter Index: ";
        cin >> index;
        if (index >= 0 && index < total_listing)
        {
            for (int i = index; i < total_listing - 1; i++)
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
    void displaySellerListings() const
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
    void updateSellerProfile()
    {
        user.updateProfile();
    }

    void VerifSeller()
    {
        if (rating >= 2.5)
        {
            verified = true;
        }
    }
    void displaySeller() const
    {
        cout << "====== Seller Details ======" << endl;
        user.viewProfile();
        cout << "ShowRoom Name: " << showroomName << endl;
        cout << "Rating: " << rating << endl;
        cout << "Verified: " << (verified ? "Yes" : "No") << endl;
        cout << "Total Listing: " << total_listing << endl;
    }

    void displytotalsellers()
    {
        cout << "Total: " << totalSeller << endl;
    }
    int getUserid()
    {
        return user.getUserId();
    }
};
int Seller::totalSeller = 0;
//-----------------Buyer Class-------------------
class Buyer
{
private:
    User user;
    string preferedBrand;
    Listing *favourites[30];
    int favouriteCount;
    double budget;

public:
    Buyer() // Default constructor initializes objects with safe default values.
    {
        favouriteCount = 0;
        budget = 0;
        preferedBrand = "";
        for (int i = 0; i < 30; i++)
        {
            favourites[i] = nullptr;
        }
    }
    // Parameterized constructor ensures object is created with valid data.

    Buyer(User u, double Budget, string preferedbrand)
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
    double getBudget()
    {
        return budget;
    }

    int getfavoriteCount()
    {
        return favouriteCount;
    }

    void setBudget(double budget)
    {
        this->budget = budget;
    }
    void saveFavorite(Listing *fav)
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
    void removeFavorite(int index)
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
    void displayFavorites()
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
    void sendMessage(MarketPlace *marketplace);
    void updateBuyerProfile()
    {
        user.updateProfile();
    }
    int getUserid()
    {
        return user.getUserId();
    }
};
//-----------------Admin Class---------------------
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
    Admin() : adminid(++totalAdmins) // Default constructor initializes objects with safe default values.
    {
        approvedCount = 0;
        removeCount = 0;
        adminlevel = 1;
    }
    // Parameterized constructor ensures object is created with valid data.
    Admin(User u, int level) : adminid(++totalAdmins)
    {
        adminlevel = level;
        user = u;
        approvedCount = 0;
        removeCount = 0;
    }
    Admin(const Admin &other) : adminid(other.adminid)
    {
        adminlevel = other.adminlevel;
        user = other.user;
        approvedCount = other.approvedCount;
        removeCount = other.removeCount;
        totalAdmins++;
    }
    void approvedlisting(Listing &l)
    {
        l.updateStatus();
        approvedCount++;
        cout << "Approved Listing!" << endl;
    }
    void removeListing(Listing &l)
    {
        l.updateStatus();
        removeCount++;
    }
    void generateReport() const
    {
        cout << "\n----- Admin Report -----\n";
        cout << "Admin ID: " << adminid << endl;
        cout << "Admin Level: " << adminlevel << endl;
        cout << "Total Approved Listings: " << approvedCount << endl;
        cout << "Total Removed Listings: " << removeCount << endl;
    }

    void displayAdminPanel() const
    {
        cout << "\n===== Admin Panel =====\n";
        cout << "Admin ID: " << adminid << endl;
        cout << "Level: " << adminlevel << endl;
    }

    void DisplayTotalAdmins()
    {
        cout << "Total Admins: " << totalAdmins << endl;
    }
    ~Admin()
    {
        totalAdmins--;
    }
};
int Admin::totalAdmins = 0;
//-------------------MarketPlace Class-----------------
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
    MarketPlace() : messages() // Default constructor initializes objects with safe default values.
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

    void getTotallisting()
    {
        cout << "Total Lisiting: " << totalListings << endl;
    }
    void gettotalusers()
    {
        cout << "Total Users: " << totalUsers << endl;
    }

    void addUser(User *u)
    {
        if (totalUsers < 100)
        {
            user[totalUsers++] = u;
            cout << "User Added!" << endl;
        }
    }

    void addListing(Listing *l)
    {
        if (totalListings < 200)
        {
            listings[totalListings++] = l;
            cout << "Listing Added!" << endl;
        }
    }
    void searchBybrand(string brand) const
    {
        bool found = false;
        for (int i = 0; i < totalListings; i++)
        {
            if (listings[i]->getcar().getBrand() == brand)
            {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No Car Found of Brand " << brand << endl;
        }
    }
    void filterByPrice(double start, double end) const
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
    void displayAllListings() const
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
    void searchBymodel(string model) const
    {
        bool found = false;
        for (int i = 0; i < totalListings; i++)
        {
            if (listings[i]->getcar().getmodel() == model)
            {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No Car Found of Model " << model << endl;
        }
    }
    void searchByYear(int year) const
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
    Listing *searchListingByid(int id) const
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
    void searchBymileage(float mileage) const
    {
        bool found = false;
        for (int i = 0; i < totalListings; i++)
        {
            if (listings[i]->getcar().getmileage() == mileage)
            {
                listings[i]->displayListing();
                found = true;
            }
        }
        if (!found)
        {
            cout << "No Car Found of Mileage " << mileage << endl;
        }
    }
    void addMessage(Message *m)
    {
        if (totalMessages < 200)
            messages[totalMessages++] = m;
    }
    ~MarketPlace()
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
};
int MarketPlace::totalUsers = 0;
int MarketPlace::totalListings = 0;
int MarketPlace::totalMessages = 0;

// Defination of Some Functions because they were causing errors

void Listing::displayListing() const
{
    cout << "ID: " << getListingid() << endl;
    car.displayCarDetails();
    seller->displaySeller();
    cout << "Asking Price: " << askingPrice << endl;
    cout << "Status: " << status << endl;
    cout << "PostDate: " << postdate << endl;
}
void Seller::addlisting(int id, Car c, double price, MarketPlace *mp)
{
    if (total_listing < 20)
    {
        Listing *l = new Listing(id, c, this, price);
        listings[total_listing++] = l;
        mp->addListing(l);

        cout << "Listing Added!" << endl;
    }
    else
    {
        cout << "Listing Limit Reached!" << endl;
    }
}
void Buyer::sendMessage(MarketPlace *marketplace)
{

    int rid;
    string text;
    cout << "\n-------Message--------\n";
    cout << "Enter Reciever Id: ";
    cin >> rid;

    cout << "Enter Your Message: ";
    cin.ignore();
    getline(cin, text);

    Message *m = new Message(user.getUserId(), rid, text);
    marketplace->addMessage(m);
    cout << "Message Sent Successfully\n";
}
// -------------Main----------------

int main()
{

    MarketPlace PakWheels;

    User *u1 = new User(1, "Ali", "ali@gmail.com", "03001234567", "Karachi");
    User *u2 = new User(2, "Ahmed", "ahmed@gmail.com", "03111234567", "Lahore");

    PakWheels.addUser(u1);
    PakWheels.addUser(u2);

    Seller s1(*u1, "Ali Motors");

    Engine e1("E123", 180, 250, 2000, "Petrol");

    Location loc1("Pakistan", "Sindh", "Karachi", "lighthouse", 75300);

    Car c1("Toyota", "Corolla", 2020, 4500000, 20000, "Automatic", e1, loc1);

    s1.addlisting(101, c1, 4700000, &PakWheels);

    Listing *l = s1.getTotallisting() > 0 ? PakWheels.searchListingByid(101) : nullptr;
    if (l == nullptr)
    {

        Listing *newListing = new Listing(101, c1, &s1, 4700000);
        PakWheels.addListing(newListing);
    }

    Buyer b1(*u2, 5000000, "Toyota");

    PakWheels.searchBybrand("Toyota");

    Listing *found = PakWheels.searchListingByid(101);
    if (found != nullptr)
        b1.saveFavorite(found);

    b1.displayFavorites();

    Admin admin1(*u1, 2);
    if (found != nullptr)
        admin1.approvedlisting(*found);

    admin1.generateReport();
    s1.updateSellerProfile();

    s1.setRating(2.3);

    Car c2(c1);
    s1.addlisting(102, c2, 3800000, &PakWheels);
    s1.displaySellerListings();
    PakWheels.displayAllListings();

    b1.sendMessage(&PakWheels);

    return 0;
}
