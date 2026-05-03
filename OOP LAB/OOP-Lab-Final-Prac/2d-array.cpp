#include <iostream>
using namespace std;
int main()
{
    int **arr = new int *[2];
    for (int i = 0; i < 2; i++)
    {
        arr[i] = new int[2];
    }

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << "Enter the value of arr[" << i << "][" << j << "] : ";
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 2; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
    arr = nullptr;
}