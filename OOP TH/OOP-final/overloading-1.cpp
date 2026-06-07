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
    complex operator-()const
    {
        return complex(-real,-img);
        
    }
    void display()
    {
        if(img >= 0){
            cout<<real<<" + "<<img<<"i"<<endl;
        }else{
            cout<<real<<" - "<<(-img)<<"i"<<endl;
        }
    }
};
int main()
{
    complex c(2, 3);
    c.display();
    c=-c;
    c.display();
}