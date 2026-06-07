#include <iostream>
using namespace std;

class complex
{
    int real;
    int img;

public:
    complex(int r = 0, int i = 0)
    {
        real = r;
        img = i;
    }
    friend ostream &operator<<(ostream &out, const complex &c);
    complex operator+(complex c)
    {
        complex temp;
        temp.real = real + c.real;
        temp.img = img + c.img;
        return temp;
    }
    complex operator-(complex c)
    {
        complex temp;
        temp.real = real - c.real;
        temp.img = img - c.img;
        return temp;
    }
    complex operator*(complex c)
    {
        complex temp;
        temp.real = real * c.real;
        temp.img = img * c.img;
        return temp;
    }
    complex operator/(complex c)
    {
        complex temp;
        temp.real = real / c.real;
        temp.img = img / c.img;
        return temp;
    }
    complex &operator=(const complex &c)
    {
        real = c.real;
        img = c.img;
        return *this;
    }
    complex &operator+=(const complex &c)
    {
        real += c.real;
        img += c.img;
        return *this;
    }
    complex &operator-=(const complex &c)
    {
        real -= c.real;
        img -= c.img;
        return *this;
    }
};
ostream &operator<<(ostream &out, const complex &c)
{
    out << c.real << " + " << c.img << "i" << endl;
    return out;
}
class counter
{
    int val;

public:
    counter(int v = 0) : val(v) {}
    counter &operator++()
    {
        val++;
        return *this;
    }
    counter operator++(int)
    {
        counter temp = *this;
        val++;
        return temp;
    }

    friend ostream &operator<<(ostream &out, const counter &c);
};
ostream &operator<<(ostream &out, const counter &c)
{
    out << "Counter value: " << c.val << endl;
    return out;
}
class nameEntry
{
    string name;

public:
    nameEntry(string n = "Unknown") : name(n) {}
    friend ostream &operator<<(ostream &out, const nameEntry &e);
    friend istream &operator>>(istream &in, nameEntry &e);
};
ostream &operator<<(ostream &out, const nameEntry &e)
{
    out << "Name: " << e.name << endl;
    return out;
}
istream &operator>>(istream &in, nameEntry &e)
{
    in >> e.name;
    return in;
}

int main()
{
    complex c1(2, 3), c2(4, 5);
    complex c3 = c1 + c2;
    complex c4 = c1 - c2;
    complex c5 = c1 * c2;
    complex c6 = c1 / c2;

    cout << "c1: ";
    cout << c1;
    cout << "c2: ";
    cout << c2;
    cout << "c1 + c2: ";
    cout << c3;
    cout << "c1 - c2: ";
    cout << c4;
    cout << "c1 * c2: ";
    cout << c5;
    cout << "c1 / c2: ";
    cout << c6;
    complex c9;
    c9 = c1;
    cout << "c9 (assigned from c1): ";
    cout << c9;
    c9 += c2;
    cout << "c9 (after += c2): ";
    cout << c9;
    c9 -= c2;
    cout << "c9 (after -= c2): ";
    cout << c9;
    counter c(5), c7(10), c8(15);
    cout << c;
    ++c7;
    cout << c7;
    c8++;
    cout << c8;

    nameEntry e;
    cout << e;
    cin >> e;
    cout << e;

    return 0;
}