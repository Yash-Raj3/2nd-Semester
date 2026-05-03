#include <iostream>
#include <string>
#include <fstream>
// Note: Removed <vector> and <stdexcept> as requested.

using namespace std;

// ==========================================
// 1. EXCEPTION HANDLING & VALIDATION
// ==========================================
// Custom exception class (Standalone, not using stdexcept)
class InvalidDataException {
private:
    string message;
public:
    InvalidDataException(string msg) { message = msg; }
    string getMessage() const {
        return message;
    }
};

// ==========================================
// 2. OOP: ABSTRACTION & ENCAPSULATION
// ==========================================
// Abstract Base Class (Interface)
class Product {
protected: // Encapsulation: properties protected so derived classes can access them
    int id;
    string name;
    double price;

public:
    // Constructor with Validation (Exception Throwing)
    Product(int id, string name, double price) {
        if (price < 0) {
            throw InvalidDataException("Validation Failed: Price cannot be negative!");
        }
        this->id = id;
        this->name = name;
        this->price = price;
    }

    virtual ~Product() {} // Virtual destructor for safe polymorphic deletion

    // Pure virtual functions (makes Product an Abstract class)
    virtual void display() const = 0; 
    virtual string getType() const = 0;

    // Getters
    int getId() const { return id; }
    string getName() const { return name; }
    double getPrice() const { return price; }

    // ==========================================
    // 3. OPERATOR OVERLOADING
    // ==========================================
    // Overloading the == operator to compare products by ID easily
    bool operator==(const Product& other) const {
        return this->id == other.id; // Two products are considered equal if their IDs match
    }
};

// ==========================================
// 4. OOP: INHERITANCE & POLYMORPHISM
// ==========================================
// Derived Class 1
class Electronics : public Product {
private:
    int warrantyMonths;

public:
    Electronics(int id, string name, double price, int warranty) 
        : Product(id, name, price) {
        this->warrantyMonths = warranty;
    }

    // Polymorphism: Overriding the base class method
    void display() const override {
        cout << "[Electronics] ID: " << id << " | Name: " << name 
             << " | Price: $" << price << " | Warranty: " << warrantyMonths << " months" << endl;
    }

    string getType() const override { return "Electronics"; }
    int getWarranty() const { return warrantyMonths; }
};

// Derived Class 2
class Clothing : public Product {
private:
    string size;

public:
    Clothing(int id, string name, double price, string size) 
        : Product(id, name, price) {
        this->size = size;
    }

    // Polymorphism: Overriding the base class method
    void display() const override {
        cout << "[Clothing]    ID: " << id << " | Name: " << name 
             << " | Price: $" << price << " | Size: " << size << endl;
    }

    string getType() const override { return "Clothing"; }
    string getSize() const { return size; }
};

// Operator Overloading (Global): Overloading << operator for easy printing of Product pointers
ostream& operator<<(ostream& os, const Product* p) {
    if (p) {
        p->display();
    }
    return os;
}

// ==========================================
// 5. TEMPLATES
// ==========================================
// A generic storage class template using raw arrays instead of vector
template <typename T>
class InventoryManager {
private:
    T* items[100]; // Fixed-size raw array of pointers
    int itemCount;

public:
    InventoryManager() {
        itemCount = 0;
        for (int i = 0; i < 100; i++) {
            items[i] = nullptr;
        }
    }

    ~InventoryManager() {
        for (int i = 0; i < itemCount; i++) {
            delete items[i];
        }
    }

    void addItem(T* item) {
        if (itemCount < 100) {
            items[itemCount] = item;
            itemCount++;
        } else {
            cout << "Inventory is full! Cannot add more items." << endl;
        }
    }

    void displayAll() const {
        if (itemCount == 0) {
            cout << "Inventory is empty." << endl;
            return;
        }
        for (int i = 0; i < itemCount; i++) {
            cout << items[i]; // This triggers our overloaded << operator!
        }
    }

    // ==========================================
    // 6. FILING (FILE HANDLING)
    // ==========================================
    void saveToFile(string filename) const {
        // ofstream: output file stream for writing
        ofstream outFile(filename, ios::out); 
        
        if (!outFile) {
            throw "Could not open file for writing: " + filename;
        }

        for (int i = 0; i < itemCount; i++) {
            // Write core attributes separated by commas
            outFile << items[i]->getType() << "," 
                    << items[i]->getId() << "," 
                    << items[i]->getName() << "," 
                    << items[i]->getPrice() << ",";
            
            // Check actual type using polymorphism to save specific child data
            if (items[i]->getType() == "Electronics") {
                Electronics* e = dynamic_cast<Electronics*>(items[i]);
                outFile << e->getWarranty() << endl;
            } else if (items[i]->getType() == "Clothing") {
                Clothing* c = dynamic_cast<Clothing*>(items[i]);
                outFile << c->getSize() << endl;
            }
        }
        outFile.close();
        cout << "Data successfully saved to " << filename << endl;
    }

    void loadFromFile(string filename) {
        // ifstream: input file stream for reading
        ifstream inFile(filename, ios::in);
        
        if (!inFile) {
            cout << "No existing data file found. Starting fresh." << endl;
            return;
        }

        string type, name, specificData;
        string idStr, priceStr;

        while (getline(inFile, type, ',')) {
            getline(inFile, idStr, ',');
            getline(inFile, name, ',');
            getline(inFile, priceStr, ',');
            getline(inFile, specificData); // read till end of line

            int id = stoi(idStr);
            double price = stod(priceStr);

            // Reconstruct the objects based on the type read from the file
            if (type == "Electronics") {
                int warranty = stoi(specificData);
                addItem(new Electronics(id, name, price, warranty));
            } else if (type == "Clothing") {
                addItem(new Clothing(id, name, price, specificData));
            }
        }
        inFile.close();
        cout << "Data successfully loaded from " << filename << endl;
    }
};

// ==========================================
// MAIN FUNCTION (Putting it all together)
// ==========================================
int main() {
    cout << "============================================" << endl;
    cout << "   COMPREHENSIVE OOP CONCEPT DEMONSTRATION  " << endl;
    cout << "============================================" << endl;
    
    // Using our Template class specifically for Product objects
    InventoryManager<Product> inventory;

    // --- 1. Filing Demo ---
    try {
        cout << "\n--- 1. Testing Filing (Load) ---" << endl;
        inventory.loadFromFile("exam_inventory_data.txt");
    } catch (string errorMsg) {
        cerr << "File Error: " << errorMsg << endl;
    }

    cout << "\n--- Current Inventory ---" << endl;
    inventory.displayAll();

    // --- 2. Exception Handling Demo ---
    cout << "\n--- 2. Testing Validation & Exceptions ---" << endl;
    try {
        // Valid additions
        inventory.addItem(new Electronics(101, "Gaming Laptop", 1200.50, 24));
        inventory.addItem(new Clothing(201, "Winter Jacket", 55.99, "L"));
        cout << "Valid items added successfully." << endl;

        // Invalid addition (negative price triggers our custom exception in constructor)
        cout << "\nAttempting to add item with invalid price (-50)..." << endl;
        inventory.addItem(new Electronics(102, "Broken Phone", -50.0, 12));
    } 
    catch (InvalidDataException e) {
        // Catching our custom exception class
        cerr << "--> CAUGHT EXCEPTION: " << e.getMessage() << endl;
    } 

    cout << "\n--- Inventory After Additions ---" << endl;
    inventory.displayAll(); // Demonstrates Polymorphism & Overloaded <<

    // --- 3. Operator Overloading Demo ---
    cout << "\n--- 3. Testing Operator Overloading ---" << endl;
    Electronics e1(301, "Tablet", 300.0, 12);
    Electronics e2(301, "Tablet Pro", 400.0, 24);
    
    cout << "Comparing Tablet (ID:301) and Tablet Pro (ID:301)..." << endl;
    if (e1 == e2) { // Uses the overloaded == operator
        cout << "--> Result: Objects match! They share the same Product ID." << endl;
    }

    // --- 4. Filing Save Demo ---
    try {
        cout << "\n--- 4. Testing Filing (Save) ---" << endl;
        inventory.saveToFile("exam_inventory_data.txt");
    } catch (string errorMsg) {
        cerr << "File Error: " << errorMsg << endl;
    }

    cout << "\nDone. Best of luck on your exam!\n";
    return 0;
}
