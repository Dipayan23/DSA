#include <iostream>
using namespace std;

void DFS(int G[][10],int n,int start){
    static int visited[10]={0};
    if(visited[start]==0){
        cout<<start<<" ";
        visited[start]=1;
        for(int j=1;j<n;j++){
            if (G[start][j]==1&&visited[j]==0)
            {
                DFS(G,n,j);
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
    
    DFS(arr,n,1);
    return 0;
}