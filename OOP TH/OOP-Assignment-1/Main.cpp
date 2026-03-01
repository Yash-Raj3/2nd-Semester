#include <iostream>
#include "User_Module.h"
#include "MarketPlace_System.h"
#include "Vehiclesystem.h"

using namespace std;

int main()
{

    MarketPlace PakWheels;

    User u1(1, "Ali", "ali@gmail.com", "03001234567", "Karachi");
    User u2(2, "Ahmed", "ahmed@gmail.com", "03111234567", "Lahore");

    PakWheels.addUser(&u1);
    PakWheels.addUser(&u2);

    Seller s1(u1, "Ali Motors");

    Engine e1("E123", 180, 250, 2000, "Petrol");

    Location loc1("Pakistan", "Sindh", "Karachi", "lighthouse", 75300);

    Car c1("Toyota", "Corolla", 2020, 4500000, 20000, "Automatic", e1, loc1);

    s1.addlisting(101, c1, 4700000);

    Listing *l = s1.getTotallisting() > 0 ? PakWheels.searchListingByid(101) : nullptr;
    if (l == nullptr)
    {

        Listing *newListing = new Listing(101, c1, &s1, 4700000);
        PakWheels.addListing(newListing);
    }

    PakWheels.displayAllListings();

    Buyer b1(u2, 5000000, "Toyota");

    PakWheels.searchBybrand("Toyota");

    Listing *found = PakWheels.searchListingByid(101);
    if (found != nullptr)
        b1.saveFavorite(found);

    b1.displayFavorites();

    Admin admin1(u1, 2);
    if (found != nullptr)
        admin1.approvedlisting(*found);

    admin1.generateReport();

    return 0;
}
