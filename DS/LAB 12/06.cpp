#include <iostream>
using namespace std;

int main()
{
    const int INF = 99999;

    int g[5][5] = {
        {0, 4, 2, INF, INF},
        {4, 0, 1, 5, INF},
        {2, 1, 0, 8, 10},
        {INF, 5, 8, 0, 2},
        {INF, INF, 10, 2, 0}};

    int dist[5], visited[5];
    for (int i = 0; i < 5; i++)
        dist[i] = INF, visited[i] = 0;

    int start = 1; // B
    dist[start] = 0;

    for (int k = 0; k < 5; k++)
    {
        int u = -1;
        for (int i = 0; i < 5; i++)
            if (!visited[i] && (u == -1 || dist[i] < dist[u]))
                u = i;

        visited[u] = 1;

        for (int v = 0; v < 5; v++)
        {
            if (g[u][v] != INF && dist[u] + g[u][v] < dist[v])
                dist[v] = dist[u] + g[u][v];
        }
    }

    cout << "Shortest distance B → E = " << dist[4];
}
