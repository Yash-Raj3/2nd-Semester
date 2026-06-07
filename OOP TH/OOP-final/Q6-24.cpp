#include <iostream>
using namespace std;

class duplicateExp : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Duplicate Item Exception";
    }
};
class ItemNotfoundExp : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Item Not Found";
    }
};
class Book
{
    int id;
    string title;
    string author;

public:
    Book() {};
    Book(int i, string t, string a)
    {
        id = i;
        title = t;
        author = a;
    }
    bool operator==(const Book &b)
    {
        if (id == b.id && title == b.title && author == b.author)
        {
            return true;
        }
        return false;
    }
};

class ChartfullExp : public exception
{
public:
    const char *what() const noexcept override
    {
        return "Out of Bound";
    }
};

template <typename T, int max_item>
class UniqueCart
{
    int item;
    T items[max_item];

public:
    UniqueCart() : item(0) {}

    bool contain(const T &Item)
    {
        for (int i = 0; i < item; i++)
        {
            if (items[i] == Item)
            {
                return true;
                break;
            }
        }
        return false;
    }
    void add(const T &Item)
    {
        if (item >= max_item)
        {
            throw ChartfullExp();
        }
        if (contain(Item))
        {
            throw duplicateExp();
        }
        items[item++] = Item;
        cout << "Item Added!" << endl;
    }
    void remove(const T &Item)
    {
        int index = -1;
        for (int i = 0; i < item; i++)
        {
            if (items[i] == Item)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            throw ItemNotfoundExp();
        }

        for (int i = index; i < item - 1; i++)
        {
            items[i] = items[i + 1];
        }
        cout << "Item Removed!" << endl;
        item--;
    }
    void display()
    {
        cout << "--------CART---------\n";
        for (int i = 0; i < item; i++)
        {
            cout << items[i] << endl;
        }
    }
};
int main()
{
    try
    {

        UniqueCart<Book, 2> cart;
        Book b1(2, "Hero Is Zero", "Yash Raj");
        cart.add(b1);
        if (cart.contain(Book(2, "Hero Is Zero", "Yash Raj")))
        {
            cout << "Item is Present!" << endl;
        }
        cart.add(Book(2, "Hero Is Zero", "Yash Raj"));
        cart.add(Book(1, "Hell is Well", "Yash"));
        cart.add(Book(3, "herooo", "Yashhhh"));
        cart.remove(Book(5, "ahhaj", "Yashhhh"));
        cart.remove(Book(1, "Hell is Well", "Yash"));
    }
    catch (const duplicateExp &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const ItemNotfoundExp &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (const ChartfullExp &e)
    {
        cout << "Error: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Another Error!" << endl;
    }
}
