// charcountC++

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of frames: ";
    cin >> n;
    string arr[100], word;
    for (int i = 0; i < n; i++)
    {
        cin >> word;
        arr[i] = word;
        string l = to_string(arr[i].length());
        word.insert(0, l);
        arr[i] = word;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i];
}