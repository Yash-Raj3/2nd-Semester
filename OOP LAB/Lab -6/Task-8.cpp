#include <iostream>
using namespace std;
class Appliance {

   public:
   bool	power;


    Appliance() :power(false){}

    void powerOn() {
        power = true;
        cout << "Power ON\n";
    }
};
class WashingMachine : public Appliance {
public:
    void wash() {
        if (power)
            cout << "Washing clothes...\n";
        else
            cout << "Turn power ON first\n";
    }
};
class SmartWashingMachine : public WashingMachine {
public:
    void smartControl() {
        cout << "Smart control activated via mobile app\n";
        wash();   
    }
};
int main() {
    SmartWashingMachine sm;
    sm.powerOn();
    sm.smartControl();

}
