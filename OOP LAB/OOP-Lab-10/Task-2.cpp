#include <iostream>
using namespace std;
template <class T>
class Demo
{
    T *arr;
public:
    void getData(int n)
    {
        arr = new T[n];
        for (int i = 0; i < n; i++)
        {
            cout << "Enter Elements " << i + 1 << ": ";
            cin >> arr[i];
        }
    }
    void display(int n)
    {
        cout << "The elements are: ";
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    T max(int n)
    {
        T max = arr[0];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
        }
        return max;
    }
};
int main()
{
    Demo<int> d1;
    d1.getData(3);
    d1.display(3);
    cout << "The maximum element is: " << d1.max(3) << endl;
}
