#include <iostream>
using namespace std;
#define INF 999
#define v 4

void floyd_warshell(int graph[][v]){
    int dist[v][v];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            dist[i][j]=graph[i][j];
        }
        
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0;j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if (dist[j][i]+dist[i][k]<dist[j][k])
                {
                    dist[j][k]=dist[j][i]+dist[i][k];
                }
                
            }
            
        }
        
    }
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            cout<<dist[i][j]<<"\t";
        }
        cout<<endl;
        
    }
    
    
}


int main(){
    int graph[v][v] = {{0, 3, INF, 5},
             {2, 0, INF, 4},
             {INF, 1, 0, INF},
             {INF, INF, 2, 0}};
  floyd_warshell(graph);
return 0;
}