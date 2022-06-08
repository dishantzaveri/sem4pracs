// nextfit

#include <bits/stdc++.h>
using namespace std;

void NextFit(int blockSize[], int m, int processSize[], int n)
{

    int allocation[n], j = 0;

    memset(allocation, -1, sizeof(allocation));

    for (int i = 0; i < n; i++)
    {

        while (j < m)
        {

            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];

                break;
            }

            j = (j + 1) % m;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << " "
             << "process " << i + 1 << " ->";

        if (allocation[i] != -1)
            cout << "block " << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

// Driver program
int main()
{
    int blockSize[] = {5, 10, 20};
    int processSize[] = {10, 20, 5};
    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    NextFit(blockSize, m, processSize, n);

    return 0;
}