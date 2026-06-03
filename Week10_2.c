#include <stdio.h>
#include <limits.h>
int main()
{
    int n;
    scanf("%d", &n);
    int cost[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(i != j && cost[i][j] == 0)
                cost[i][j] = INT_MAX;
        }
    }
    int visited[n];
    for(int i = 0; i < n; i++)
        visited[i] = 0;
    visited[0] = 1;
    int edges = 0;
    int mincost = 0;

    while(edges < n - 1)
    {
        int min = INT_MAX;
        int a = -1, b = -1;
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
            {
                for(int j = 0; j < n; j++)
                {
                    if(!visited[j] && cost[i][j] < min)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("%d %d %d\n", a, b, min);
        mincost += min;
        visited[b] = 1;
        edges++;
    }
    printf("%d\n", mincost);
    return 0;
}

