#include <iostream>
using namespace std;

int graph[10][10];
int visited[10];
int adjList[10][10];
int countList[10];

void addEdge(int u, int v)
{
    graph[u][v] = 1;
    graph[v][u] = 1;

    adjList[u][countList[u]++] = v;
    adjList[v][countList[v]++] = u;
}

void BFS(int start)
{
    int q[20], front = 0, rear = 0;
    visited[start] = 1;
    q[rear++] = start;

    while (front < rear)
    {
        int u = q[front++];
        cout << u << " ";
        for (int i = 0; i < countList[u]; i++)
        {
            int v = adjList[u][i];
            if (!visited[v])
            {
                visited[v] = 1;
                q[rear++] = v;
            }
        }
    }
}

void DFSUtil(int u)
{
    visited[u] = 1;
    cout << u << " ";
    for (int i = 0; i < countList[u]; i++)
    {
        int v = adjList[u][i];
        if (!visited[v])
            DFSUtil(v);
    }
}

void DFS(int start)
{
    DFSUtil(start);
}

int main()
{
    addEdge(0, 1);
    addEdge(0, 2);
    addEdge(1, 3);
    addEdge(2, 4);
    addEdge(3, 4);

    cout << "Adjacency Matrix\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << graph[i][j] << " ";
        cout << "\n";
    }

    cout << "\nAdjacency List\n";
    for (int i = 0; i < 5; i++)
    {
        cout << i << ": ";
        for (int j = 0; j < countList[i]; j++)
            cout << adjList[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < 10; i++)
        visited[i] = 0;
    cout << "\nBFS: ";
    BFS(0);

    for (int i = 0; i < 10; i++)
        visited[i] = 0;
    cout << "\nDFS: ";
    DFS(0);
}
