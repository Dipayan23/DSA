#include <iostream>
using namespace std;
#define n 4
bool isSafe(int graph[n][n], int color[n], int c, int v)
{
    for (int i = 0; i < n; i++)
    {
        if (color[i] == c && graph[v][i] == 1)
        {
            return false;
        }
    }
    return true;
}
void display(int color[])
{
    for (int i = 0; i < n; i++)
    {
        cout << color[i] << "\t";
    }
    cout << endl;
}

bool allCombination(int graph[n][n], int color[n], int m, int v)
{
    if (n == v)
    {
        display(color);
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(graph, color, i, v))
        {
            color[v] = i;
            if (allCombination(graph, color, m, v + 1))
            {
                return true;
            }
            color[v] = 0;
        }
    }

    return false;
}

int main()
{
    int graph[n][n] = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = 3;
    int color[n];
    for (int i = 0; i < n; i++)
        color[i] = 0;
    if (allCombination(graph, color, m, 0) == false)
    {
        cout << "No Solution Exist" << endl;
    }

    return 0;
}