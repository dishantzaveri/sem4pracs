// hamming2

#include <bits/stdc++.h>
using namespace std;

int isPowerofTwo(int a)
{
    int i = 0;
    while (pow(2, i) <= a)
    {
        if (pow(2, i) == a)
        {
            return 1;
        }
        else
        {
            i++;
        }
    }
    return 0;
}

int findredundant(int m)
{
    int r = 0;
    while (true)
    {
        if (pow(2, r) >= (m + r + 1))
        {
            return r;
        }
        else
        {
            r++;
        }
    }
    return -1;
}

void reverse_arr(int arr[], int n)
{
    int temp, start = 0, end = n;
    while (start < end)
    {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void create_hamming(int transdata[], int m, int r)
{
    int n = m + r;

    for (int k = 0; k < r; k++)
    {
        int i = pow(2, k) - 1;
        if (transdata[i] == -1)
        {
            int p = -20;
            for (int j = i; j < n;)
            {
                int bunch = i + 1;
                while (j < n)
                {
                    if (i == j)
                    {
                        j++;
                        bunch--;
                    }
                    else
                    {
                        if (p == -20)
                        {
                            p = transdata[j];
                        }
                        else
                        {
                            p = p ^ transdata[j];
                        }
                        j++;
                        bunch--;
                    }
                    if (bunch == 0)
                    {
                        bunch = i + 1;
                        j += bunch;
                    }
                }
            }
            transdata[i] = p;
        }
    }
}

void error_hamming(int recdata[], int m, int r)
{

    int n = m + r, corrbit = 0;
    bool err = false;

    for (int k = 0; k < r; k++)
    {
        int i = pow(2, k) - 1;
        int p = -20;
        for (int j = i; j < n;)
        {
            int bunch = i + 1;
            while (j < n)
            {
                if (p == -20)
                {
                    p = recdata[j];
                }
                else
                {
                    p = p ^ recdata[j];
                }
                j++;
                bunch--;
                if (bunch == 0)
                {
                    bunch = i + 1;
                    j += bunch;
                }
            }
        }
        if (p == 1)
        {
            err = true;
            corrbit += pow(2, k);
        }
    }
    cout << "Corrupted bit no is " << corrbit << endl;
    cout << "Corrected code is: ";
    for (int i = n - 1; i >= 0; i--)
    {
        if (i != (corrbit - 1))
        {
            cout << recdata[i] << " ";
        }
        else
        {
            cout << !recdata[i] << " ";
        }
    }
    cout << endl;
}

int main()
{
    int m, r;

    cout << "Enter the number of databits: ";
    cin >> m;

    r = findredundant(m);

    int n = m + r, transdata[n], data[m], recdata[n];

    cout << "Enter databits: ";
    for (int i = 0; i < m; i++)
    {

        cin >> data[i];
    }

    int i = 0, j = m - 1;

    while (i < n && j >= 0)
    {
        if (!isPowerofTwo(i + 1))
        {
            transdata[i] = data[j];
            i++, j--;
        }
        else
        {
            transdata[i] = -1;
            i++;
        }
    }

    create_hamming(transdata, m, r);

    for (int i = n - 1; i >= 0; i--)
    {
        cout << transdata[i] << " ";
    }
    cout << endl;

    cout << "Enter received databit: ";
    for (int i = n - 1; i >= 0; i--)
    {

        cin >> recdata[i];
    }

    error_hamming(recdata, m, r);

    return 0;
}