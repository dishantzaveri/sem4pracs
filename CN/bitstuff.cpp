// bitstuffing

#include <iostream>
using namespace std;

int main()
{
    string data;
    cout << "Enter flag: ";
    cin >> data; // 1111111
    int count = 0;
    string arr[data.length() + 1]; // arr[12]
    int j = 0;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (data[j] == '1')
        {
            count++; // 6
            if (count == 6)
            {
                count = 0;
                arr[i] = '0';
            }
            else
            {
                arr[i] = data[j];
                j++;
            }
        }
        else
        {
            count = 0;
            arr[i] = data[i];
            j++;
        }
    }
    for (int i = 0; i < data.length() + 1; i++)
    {
        cout << arr[i];
    }
    return 0;
}