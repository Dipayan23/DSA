#include <iostream>
#include <queue>
#include<deque>
using namespace std;

void BFS(int** arr,int n)
{
    int visited[n + 1] = {0};
    queue<int> q;
    int i = 1;
    cout << i << " ";
    q.push(i);
    visited[i] = 1;
    while (!q.empty())
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                q.push(j);
                visited[j] = 1;
            }
        }
        q.pop();
        i=q.front(); 
    }
}

int main()
{
    int arr[5][5] = { {0, 0, 0, 0, 0},
                      {0, 0, 1, 0, 1},
                      {0, 1, 0, 1, 0},
                      {0, 0, 1, 0, 0},
                      {0, 1, 0, 0, 0} };
    BFS((int**)arr,5);
    return 0;
}