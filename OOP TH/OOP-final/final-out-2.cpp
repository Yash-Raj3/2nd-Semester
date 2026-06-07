#include <iostream>
using namespace std;

class Universe
{
    static int count;
    int id;

public:
    Universe() : id(++count) { cout << "Universe #" << id << " created." << endl; }
    ~Universe() { cout << "Universe #"
                       << id << " destroyed." << endl; }
    static void reset() { count = 0; }
};
int Universe::count = 0;
int main()
{
    Universe::reset();
    Universe u1, u2;

    Universe u3;
    Universe *u4 = new Universe();
    delete u4;
    return 0;
}