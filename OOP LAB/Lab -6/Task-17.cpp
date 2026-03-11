#include <iostream>
using namespace std;
class Machine {
public:
    void start() {
        cout << "Machine Started" << endl;
    }
};
class Printer : virtual public Machine {
};
class Scanner : virtual public Machine {
};
class AllInOne : public Printer, public Scanner {
};
int main() {
    AllInOne obj;
    obj.start();   // No ambiguity
Machine * m1= (Printer*)&obj;
Machine * m2 = (Scanner*)&obj;
    cout << "Address via Printer path: " << m1 << endl;
    cout << "Address via Scanner path: " << m2 << endl;
}
