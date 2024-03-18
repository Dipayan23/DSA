#include <iostream>
#include <queue>
using namespace std;

void BFS(int n,int arr[][10])
{
    int visited[n + 1] = {0};
    queue<int> q;
    int i = 1;
    cout << i << " ";
    q.push(i);
    visited[i] = 1;
    while (!q.empty())
    {
        i=q.front(); 
        q.pop();
        for (int j = 1; j <= n; j++)
        {
            if (arr[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                q.push(j);
                visited[j] = 1;
            }
        }
        
    }
}

int main()
{
    int arr[10][10]={0};
    cout<<"Enter the number of vertice :";
    int n;
    cin>>n;
    cout<<"Enter the adjecent :"<<endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p;
            cin>>p;
            arr[i][j]=p;  
        }
        
    }
    
    BFS(5,arr);
    return 0;
}