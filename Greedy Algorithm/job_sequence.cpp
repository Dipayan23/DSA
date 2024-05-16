#include <iostream>
using namespace std;

void sorting(int p[], int d[], int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (p[j] < p[j + 1])
            {
                swap(p[j], p[j + 1]);
                swap(d[j], d[j + 1]);
            }
        }
    }
}

int max_of_array(int arr[],int n){
    int max=0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i]<arr[i+1])
        {
           max=arr[i+1];
        }
        
    }
    return max;
    
}

void display(int p[], int d[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << p[i] << "\t" << d[i] << endl;
    }
}

int job_sequence(int p[],int d[],int n){
    sorting(p,d,n);
    int max=max_of_array(d,n);
    int g[max+1]={0};
    for (int i = 1; i <= n; i++)
    {
        for (int j = d[i]; j > 0; j--)
        {
            if (g[j]==0)
            {
                g[j]=p[i];
                break;
            }
            
        }
        
    }
    int profit=0;
    for (int i = 1; i < max+1; i++)
    {
        profit+=g[i];
    }
    return profit;
}


int main()
{
    int p[9] = {0, 40, 30, 10, 60, 70, 10, 50, 20};
    int d[9] = {0, 2, 6, 9, 1, 3, 3, 2, 4};
    sorting(p, d, 8);
    display(p, d, 8);
    cout<<job_sequence(p,d,8);
    return 0;
}