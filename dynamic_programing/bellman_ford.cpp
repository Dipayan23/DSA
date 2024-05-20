#include <iostream>
using namespace std;

void bellman_ford(int graph[][3],int src,int v,int e){
    int dist[v];
    for (int i = 0; i < v; i++)
    {
        dist[i]=999;
    }
    dist[src]=0;
    for (int i = 0; i < v-1; i++)
    {
        for (int j = 0; j < e; j++)
        {
            if (dist[graph[j][0]]!=999 && dist[graph[j][0]]+graph[j][2]<dist[graph[j][1]])
            {
                dist[graph[j][1]]=dist[graph[j][0]]+graph[j][2];
            }
            
        }
        
    }
    for (int i = 0; i < e; i++)
    {
        int x=graph[i][0];
        int y=graph[i][1];
        int weight=graph[i][2];
        if (x!=999&&dist[x]+weight<dist[y])
        {
            cout<<"The graph contain negative edge cycle"<<endl;
            return;
        }
        
    }
    for (int i = 0; i < v; i++)
    {
        cout<<src<<"---"<<"("<<dist[i]<<")"<<"-->"<<i<<endl;
    }
    
    
}

int main(){
    int V = 5; // Number of vertices in graph
    int E = 8;
    int graph[][3] = { { 0, 1, -1 }, { 0, 2, 4 },
                       { 1, 2, 3 }, { 1, 3, 2 }, 
                       { 1, 4, 2 }, { 3, 2, 5 }, 
                       { 3, 1, 1 }, { 4, 3, -3 } };
    bellman_ford(graph,0,V,E);
return 0;
}