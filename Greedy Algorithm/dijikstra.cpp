#include <iostream>
using namespace std;
#define v 5

// Finding the minimum values index

int min_index(int dist[], bool sptSet[])
{
    int min = 999;
    int min_key = -1;
    for (int i = 0; i < v; i++)
    {
        if (sptSet[i] == false && dist[i] <= min)
        {
            min = dist[i];
            min_key = i;
        }
    }
    return min_key;
}

// Display Function

void display(int dist[], int src)
{
    for (int i = 0; i < v; i++)
    {
        cout << "From " << src << " to " << i << " -----> " << dist[i] << endl;
    }
}

// Dijikstra algorithm

void dijikstra(int graph[v][v], int src)
{
    bool sptSet[v];
    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i] = 999;
        sptSet[i] = false;
    }
    dist[src] = 0;
    for (int i = 0; i < v - 1; i++)
    {
        int u = min_index(dist, sptSet);
        sptSet[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (!sptSet[j] && graph[u][j] && dist[u] != 999 && dist[u] + graph[u][j] < dist[j])
            {
                dist[j] = dist[u] + graph[u][j];
            }
        }
    }
    display(dist, src);
}
int main()
{
    int graph[v][v] = {{0, 2, 0, 0, 0}, // Vertex 0
                       {2, 0, 3, 0, 0}, // Vertex 1
                       {0, 3, 0, 1, 0}, // Vertex 2
                       {0, 0, 1, 0, 4}, // Vertex 3
                       {0, 0, 0, 4, 0}};
    dijikstra(graph, 0);
    return 0;
}