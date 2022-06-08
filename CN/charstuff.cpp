// charstuffc++

#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int n, count = 0;
    cout << "Enter length of data: ";
    cin >> n;
    string word;
    cout << "Enter data: ";
    cin >> word;
    char delimiter;
    cout << "Enter delimiter: ";
    cin >> delimiter;
    for (int i = 0; i < n; i++)
        if (word.at(i) == delimiter)
            word.insert(i++, "#");
    cout << word << endl;
}