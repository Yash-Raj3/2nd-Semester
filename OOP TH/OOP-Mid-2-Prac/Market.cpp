#include <iostream>
using namespace std;

class Product
{
    string name;
    string MFG;
    string EXP;
    double price;
    string Ingredients;

public:
    Product(string n = "", string m = "", string e = "", double p = 0, string i = "")
    {
        name = n;
        MFG = m;
        EXP = e;
        price = p;
        Ingredients = i;
    }
    void Setingredients()
    {
        cout << "Enter the ingredients of the product(Higher-Lower): ";
        cin.ignore();
        getline(cin, Ingredients);
    }
    void display()
    {
        cout << "Product Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "MFG: " << MFG << endl;
        cout << "EXP: " << EXP << endl;
        cout << "Price: " << price << endl;
        cout << "Ingredients: " << Ingredients << endl;
    }
};
class Market
{
    string name;
    string location;
    Product products[100];
    int productCount;

public:
    Market(string n = "", string l = "")
    {
        name = n;
        location = l;
        productCount = 0;
    }
    void addProduct(Product p)
    {
        products[productCount++] = p;
    }
    void displayProducts()
    {
        cout << "Market: " << name << " Location: " << location << endl;
        for (int i = 0; i < productCount; i++)
        {
            products[i].display();
            cout << "-----------------------" << endl;
        }
    }
};
int main()
{
    Market market("Fresh Mart", "Downtown");
    Product p1("Milk", "01-01-2024", "01-01-2025", 2.5);
    p1.Setingredients();
    Product p2("Bread", "01-02-2024", "01-02-2024", 1.0);
    p2.Setingredients();
    market.addProduct(p1);
    market.addProduct(p2);
    market.displayProducts();
    return 0;
}