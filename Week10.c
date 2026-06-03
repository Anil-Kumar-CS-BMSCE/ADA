#include <stdio.h>
struct Edge
{
    int u, v, w;
};
int parent[100];
int find(int i)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}
void unionSet(int a, int b)
{
    parent[a] = b;
}
int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    struct Edge edge[e];
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (edge[j].w > edge[j + 1].w)
            {
                struct Edge temp = edge[j];
                edge[j] = edge[j + 1];
                edge[j + 1] = temp;
            }
        }
    }
    int minCost = 0;
    for (int i = 0; i < e; i++)
    {
        int a = find(edge[i].u);
        int b = find(edge[i].v);
        if (a != b)
        {
            printf("%d %d %d\n",
                   edge[i].u,
                   edge[i].v,
                   edge[i].w);
            minCost += edge[i].w;
            unionSet(a, b);
        }
    }
    printf("%d\n", minCost);
    return 0;
}
