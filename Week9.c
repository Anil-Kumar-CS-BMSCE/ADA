#include <stdio.h>
int main()
{
    int n, e;
    scanf("%d %d", &n, &e);
    int adj[n][n];
    int indegree[n];
    for(int i = 0; i < n; i++)
    {
        indegree[i] = 0;
        for(int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
    for(int i = 0; i < e; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        indegree[v]++;
    }
    int queue[n];
    int front = 0, rear = 0;
    for(int i = 0; i < n; i++)
    {
        if(indegree[i] == 0)
            queue[rear++] = i;
    }
    while(front < rear)
    {
        int u = queue[front++];
        printf("%d ", u);
        for(int v = 0; v < n; v++)
        {
            if(adj[u][v] == 1)
            {
                indegree[v]--;
                if(indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }
    return 0;
}
