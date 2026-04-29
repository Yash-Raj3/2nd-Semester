#include <iostream>
using namespace std;

class Notification
{
protected:
    string reciepient;

public:
    Notification(string reciepient)
    {
        this->reciepient = reciepient;
    }
    virtual void sendNotification() = 0;
};
class EmailNotification : public Notification
{
public:
    EmailNotification(string reciepient) : Notification(reciepient) {}
    void sendNotification()
    {
        cout << "\n----Email Notification----\n";
        cout << "To: " << reciepient << endl;
        cout << "Your OTP is 123456. Please do not share it with anyone." << endl;
        cout << "Status: Sent successfully!" << endl;
        cout << "-----------------------------\n";
    }
};
class SMSNotification : public Notification
{
public:
    SMSNotification(string reciepient) : Notification(reciepient) {}
    void sendNotification()
    {
        cout << "\n----SMS Notification----\n";
        cout << "To: " << reciepient << endl;
        cout << "Your OTP is 123456. Please do not share it with anyone." << endl;
        cout << "Status: Sent successfully!" << endl;
        cout << "-----------------------------\n";
    }
};
class PushNotification : public Notification
{
public:
    PushNotification(string reciepient) : Notification(reciepient) {}
    void sendNotification()
    {
        cout << "\n----Push Notification----\n";
        cout << "To: " << reciepient << endl;
        cout << "Your OTP is 123456. Please do not share it with anyone." << endl;
        cout << "Status: Sent successfully!" << endl;
        cout << "-----------------------------\n";
    }
};
int main()
{
    Notification *n1;
    EmailNotification email("qasim@gmail.com");
    SMSNotification sms("03343329938");
    PushNotification push("Mahboor Ali");

    n1 = &email;
    n1->sendNotification();

    n1 = &sms;
    n1->sendNotification();

    n1 = &push;
    n1->sendNotification();
}
