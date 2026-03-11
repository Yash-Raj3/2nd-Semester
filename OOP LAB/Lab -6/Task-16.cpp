#include<iostream>
using namespace std;
class Machine {
public:
    void start() {
        cout << "Machine Started" << endl;
    }
};
class Printer : public Machine {
};
class Scanner : public Machine {
};
class AllInOne : public Printer, public Scanner {
};
int main() {
    AllInOne obj;

    obj.start();   // Ambiguous call
}


