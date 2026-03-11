#include <iostream>
using namespace std;
class Base
{
public:
    int publicVar = 10;

protected:
    int protectedVar = 20;

private:
    int privateVar = 30;
};
class PublicDerived : public Base
{
public:
    void show()
    {
        cout << "PublicDerived accessing publicVar: " << publicVar << endl;
        cout << "PublicDerived accessing protectedVar: " << protectedVar << endl;
        // cout << privateVar; // Not accessible
    }
};
class ProtectedDerived : protected Base
{
public:
    void show()
    {
        cout << "ProtectedDerived accessing publicVar: " << publicVar << endl;
        cout << "ProtectedDerived accessing protectedVar: " << protectedVar << endl;
        // cout << privateVar; // Not accessible
    }
};
class PrivateDerived : private Base
{
public:
    void show()
    {
        cout << "PrivateDerived accessing publicVar: " << publicVar << endl;
        cout << "PrivateDerived accessing protectedVar: " << protectedVar << endl;
        // cout << privateVar; // Not accessible
    }
};
int main()
{
    PublicDerived pd;
    pd.show();
    cout << "Accessing publicVar from main through PublicDerived: " << pd.publicVar << endl;
    // cout << pd.protectedVar; // Not accessible
    // cout << pd.privateVar;   // Not accessible

    ProtectedDerived protd;
    protd.show();
    // cout << protd.publicVar; // Not accessible 

    PrivateDerived privd;
    privd.show();
    // cout << privd.publicVar; // Not accessible
}
