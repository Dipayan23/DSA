#include <iostream>
using namespace std;

#define v 5

void display_array(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<"\t";
    }
    
    
}

int minKey(int key[], bool mstSet[])
{
    int min = 999;
    int min_key_index;
    //display_array(key,v);
    for (int i = 0; i < v; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_key_index = i;
        }
    }
    
    return min_key_index;
    
}

void printMST(int parent[], int graph[v][v])
{
    cout << "Edge"
         << "\t"
         << "weight"<<endl;
    for (int i = 1; i < v; i++)
    {
        cout << parent[i] << "----" << i << "\t" << graph[i][parent[i]] << endl;
    }
}

void primMST(int graph[v][v])
{
    int parent[v];
    int key[v];
    bool mstSet[v];

    for (int i = 0; i < v; i++)
    {
        mstSet[i] = false;
        key[i] = 999;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < v - 1; i++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;
        for (int j = 0; j < v; j++)
        {
            if (graph[u][j] && mstSet[j] == false && graph[u][j] < key[j])
            {
                parent[j] = u;
                key[j] = graph[u][j];
            }
        }
        //display_array(key,v);
    }
    //display_array(parent,v);
    printMST(parent, graph);
}

int main()
{
    int graph[v][v] = {{0,2,0,6,0},
                       {2,0,3,8,5},
                       {0,3,0,0,7},
                       {6,8,0,0,9},
                       {0,5,7,9,0}};
    primMST(graph);
    return 0;
}