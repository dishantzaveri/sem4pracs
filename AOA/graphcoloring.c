// graphcoloring

#include <stdio.h>
#define MAX 100
int x[MAX];
int adj[MAX][MAX];
int n, m;
void nValue(int k)
{
    int i;
    while (1)
    {
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0)
            return;
        for (i = 0; i < n; i++)
        {
            if (adj[i][k] != 0 && x[i] == x[k])
                break;
        }
        if (i == n)
            return;
    }
}
void nColor(int k)
{
    int i;
    while (1)
    {
        nValue(k);
        if (x[k] == 0)
            return;
        if (k == n)
        {
            for (i = 0; i < n; i++)
            {
                printf("%d ", x[i]);
            }
            printf("\n");
            break;
        }
        else
            nColor(k + 1);
    }
}
int main()
{
    int i, j;
    printf("enter no of elements:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("enter no of colors:\n");
    scanf("%d", &m);
    nColor(0);
}