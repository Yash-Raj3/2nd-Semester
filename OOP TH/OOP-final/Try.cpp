#include <iostream>
class Base
{
public:
    static int count;
    Base() { count++; }
    virtual ~Base() { count--; }
    static void printCount()
    {
        std::cout << "Count: " << count << std::endl;
    }
};
class Derived : public Base
{
public:
    Derived() { count++; }
    ~Derived() { count--; }
};
int Base::count = 0;
int main()
{
    Base::printCount();
    {
        Base obj1;
        Derived obj2;
        Base::printCount();
    }
    Base::printCount();

    return 0;
}