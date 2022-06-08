// hamming

#include <math.h>
#include <stdio.h>
#define max 100
int data[max];
int hamm[max];
int d_c[max];
int cal(int pos, int len)
{
    int i = pos, j;
    int count = 0;
    while (i < len)
    {
        for (j = i; j <= i + pos; j++)
        {
            if (hamm[j] == 1)
                count++;
        }
        i += ((pos + 1) * 2);
    }
    if (count % 2 == 0)
        return 0;
    else
        return 1;
}
void hamming(int p, int n)
{
    int i, j, k;
    for (i = n - 1, j = 0; i >= 0; i--, j++)
        d_c[j] = data[i];
    for (i = 0; i < p; i++)
    {
        j = (int)pow(2, i);
        hamm[j - 1] = -1;
    }
    for (i = 0, j = 0; i < (n + p); i++)
    {
        if (hamm[i] != -1)
        {
            hamm[i] = d_c[j];
            j++;
        }
    }
    for (i = 0, j = 0; i < (n + p); i++)
    {
        if (hamm[i] == -1)
        {
            k = cal(i, (n + p));
            hamm[i] = k;
        }
    }
}
void main()
{
    int i, n, p, c;
    printf("Enter length of data: ");
    scanf("%d", &n);
    for (i = 0; i <= n; i++)
    {
        c = (int)pow(2, i);
        if (c > (n + i - 1))
        {
            p = i;
            break;
        }
    }
    printf("The number of parity bits are %d\n", p);
    printf("Enter data: ");
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);
    hamming(p, n);
    printf("\nHamming code is ");
    for (i = n + p - 1; i >= 0; i--)
        printf("%d", hamm[i]);
    printf("\n");
}