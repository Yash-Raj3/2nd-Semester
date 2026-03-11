#include <iostream>
using namespace std;
class Device
{
protected:
    string brand;
    int powerRating;

public:
    Device(string b, int p)
    {
        brand = b;
        powerRating = p;
    }

    void showDevice()
    {
        cout << "Brand: " << brand << endl;
        cout << "Power Rating: " << powerRating << "W" << endl;
    }
};
class Computer : public Device
{
protected:
    string processor;
    int ram;

public:
    Computer(string b, int p, string proc, int r)
        : Device(b, p)
    {
        processor = proc;
        ram = r;
    }

    void showComputer()
    {
        cout << "Processor: " << processor << endl;
        cout << "RAM: " << ram << "GB" << endl;
    }
};
class Network
{
protected:
    string ipAddress;
    int bandwidth;

public:
    Network(string ip, int bw)
    {
        ipAddress = ip;
        bandwidth = bw;
    }

    void showNetwork()
    {
        cout << "IP Address: " << ipAddress << endl;
        cout << "Bandwidth: " << bandwidth << " Mbps" << endl;
    }
};


class Server : public Computer, public Network
{
private:
    string serverType;

public:
    Server(string b, int p, string proc, int r,
           string ip, int bw, string type)
        : Computer(b, p, proc, r),
          Network(ip, bw)
    {
        serverType = type;
    }

    void showServer()
    {
        cout << "Server Type: " << serverType << endl;
    }

    void displayAll()
    {
        showDevice();    
        showComputer();  
        showNetwork();   
        showServer();  
    }
};
int main()
{
    Server s("Dell", 750, "Intel i7 ", 64,
             "192.168.1.10", 1000, "Web Server");

    s.displayAll();

    
}
