#include <iostream>
using namespace std;
class Device {
public:
    void powerOn() {
        cout << "Device Power On" << endl;
    }
};
class Camera : virtual public Device {
public:
    void takePhoto() {
        cout << "Photo Captured" << endl;
    }
};
class Phone : virtual public Device {
public:
    void makeCall() {
        cout << "Calling..." << endl;
    }
};
class SmartPhone : public Camera, public Phone {
public:
    void useApps() {
        cout << "Using Smartphone Apps" << endl;
    }
};
int main() {
    SmartPhone obj;
    obj.powerOn();     
    obj.takePhoto();   
    obj.makeCall();    
    obj.useApps();     
}
