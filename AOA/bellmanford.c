// Bellman Ford

#include <stdio.h>
#define MAX 100
#define OG 999
int edge1[MAX], edge2[MAX];
int cost[MAX][MAX];
int list[MAX];
int nodes[MAX];
int distance[MAX], parent[MAX];
void initialize(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        list[nodes[i]] = 0;
        distance[nodes[i]] = OG;
        parent[nodes[i]] = OG;
    }
    distance[nodes[0]] = 0;
}
void relax(int u, int v)
{
    if (distance[v] == OG && distance[u] == OG)
    {
        return;
    }
    if (distance[v] == OG)
    {
        distance[v] = distance[u] + cost[u][v];
        return;
    }
    distance[v] = (distance[v] > distance[u] + cost[u][v]) ? distance[u] + cost[u][v] : distance[v];
}
int extractMin(int n)
{
    int i;
    int min = MAX;
    int mini = -1;
    for (i = 0; i < n; i++)
    {
        if (distance[i] < min && list[i] != 1)
        {
            mini = i;
            min = distance[i];
        }
    }
    if (mini != -1)
        list[mini] = 1;
    return mini;
}
void bellmanFord(int n, int e)
{
    int i, j;
    for (j = 0; j < n - 1; j++)
    {
        for (i = 0; i < e; i++)
        {
            relax(edge1[i], edge2[i]);
        }
        for (i = 0; i < n; i++)
        {
            printf("%d\t", distance[nodes[i]]);
        }
        printf("\n");
    }
}
int main()
{
    int i, j, k, n, e, u, v, a, b, w;
    int l;
    printf("Number of nodes:\n");
    scanf("%d", &n);
    printf("Enter nodes:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nodes[i]);
    }
    printf("Number of edges:\n");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[nodes[i]][nodes[j]] = OG;
        }
    }
    printf("Enter the startnode endnode weight:\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        edge1[i] = a;
        edge2[i] = b;
        cost[a][b] = w;
    }
    initialize(n);
    bellmanFord(n, e);
    printf("The final distants are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", distance[nodes[i]]);
    }
}