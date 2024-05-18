#include <iostream>
using namespace std;

void display_arr(int arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void display_arr_float(float arr[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
void swaping_arr(float arr[],int i,int j){
    float x=arr[i];
    arr[i]=arr[j];
    arr[j]=x;
}

void swaping_arr_int(int arr[],int i,int j){
    float x=arr[i];
    arr[i]=arr[j];
    arr[j]=x;
}

void sort(int w[], int p[], int n)
{
    float p_w[n + 1];
    for (int i = 1; i <= n; i++)
    {
        p_w[i] = (float)p[i] / w[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (p_w[j] < p_w[j + 1])
            {
                swaping_arr(p_w,j,j+1);
                swaping_arr_int(p,j,j+1);
                swaping_arr_int(w,j,j+1);
            }
        }
    }
    display_arr_float(p_w,n);
}

int knapSack(int p[],int w[],int n,int W){
    int x[n+1]={0};
    sort(w,p,n);
    int u=W;
    for (int i = 1; i <= n; i++)
    {
        if (u<w[i])
        {
            break;
        }
        else
        {
            x[i]=1;
            u-=w[i];
        }
        
        
    }
    int profit=0;
    for (int i = 1; i <=n; i++)
    {
        if (x[i]==1)
        {
            profit+=p[i];
        }
        
    }
    return profit;

}

int main()
{
    int w[8] = {0, 2, 3, 5, 7, 1, 4, 1};
    int p[8] = {0, 10, 5, 15, 7, 6, 18, 3};
    int profit=knapSack(p,w,7,15);
    cout<<profit;
    return 0;
}