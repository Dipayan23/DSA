#include <iostream>
#include <stdio.h>
using namespace std;

#define v 5
int parent[v];

int find(int i)
{
    while (i != parent[i])
    {
        i = parent[i];
    }
    return i;
}

void union1(int i, int j)
{
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int graph[v][v])
{
    int min_cost = 0;
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }
    int edge_count = 0;
    while (edge_count < v - 1)
    {
        int min = 999, a = -1, b = -1;
        for (int i = 0; i < v; i++)
        {
            for (int j = 0; j < v; j++)
            {
                if (find(i) != find(j) && min > graph[i][j] && graph[i][j] != 0)
                {
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        union1(a, b);
        cout << a << "----" << min << "----" << b << endl;
        min_cost += min;
        edge_count++;
    }
    cout << min_cost;
}

int main()
{
    int graph[v][v] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9, 0}};
    kruskal(graph);
    return 0;
}