#include <iostream>
#include <stdlib.h>
using namespace std;

class Student
{
private:
    int marks[5];

public:
    friend void calculateAverage(Student s);
    void input()
    {
        int i = 0;
        while (i < 5)
        {
            cout << "Enter Sub " << i + 1 << " Marks(0-100): ";
            cin >> marks[i];
            if (marks[i] >= 0 && marks[i] <= 100)
            {
                i++;
            }
        }
    }
};
void calculateAverage(Student s)
{
    float sum = 0;
    for (int i = 0; i < 5; i++)
    {
        sum += s.marks[i];
    }
    cout << "Average : " << sum / 5 << endl;
}

int main()
{
    system("color 04");
    Student s1;
    s1.input();
    calculateAverage(s1);
}