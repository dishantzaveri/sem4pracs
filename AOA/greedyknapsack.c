// greedyknapsack
#include <stdio.h>
#define MAX 100
int n, m, c;
int p[MAX], w[MAX];
struct el
{
    int p, w;
};
struct el s[MAX];
void knapsack()
{
    int i, j;
    int ct, max;
    s[0].p = 0;
    s[0].w = 0;
    c = 1;
    for (i = 0; i < n; i++)
    {
        struct el temp[MAX];
        // printf("{");
        ct = 0;
        for (j = 0; j < c; j++)
        {
            temp[j].p = p[i] + s[j].p;
            temp[j].w = w[i] + s[j].w;
            // printf("(%d,%d) , ",temp[j].p,temp[j].w);
            ct++;
        }
        // printf("}\n");
        for (j = 0; j < ct; j++)
        {
            if (temp[j].w <= m)
            {
                s[c] = temp[j];
                c++;
            }
        }
        max = 0;
        printf("{");
        for (j = 0; j < c; j++)
        {
            printf("(%d,%d) , ", s[j].p, s[j].w);
            max = (max > s[j].p) ? max : s[j].p;
        }
        printf("}\n");
    }
}
int main()
{
    int i;
    printf("enter no of elements:\n");
    scanf("%d", &n);
    printf("enter weight and profit:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &w[i], &p[i]);
    }
    printf("enter max weight:\n");
    scanf("%d", &m);
    knapsack();
}