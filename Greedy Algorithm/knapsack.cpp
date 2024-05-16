#include <iostream>
using namespace std;

void display_float(float arr[],int n){
    for (int i = 1; i < n; i++)
    {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
    
}

void swaping_arr(float arr[],int i,int j){
    float x=arr[i];
    arr[i]=arr[j];
    arr[j]=x;
}

void sort(float w[], float p[], int n)
{
    float p_w[n + 1];
    
    for (int i = 1; i <= n; i++)
    {
        
        p_w[i] = p[i] / w[i];
        
    }
    //display_float(p_w,n+1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (p_w[j] < p_w[j + 1])
            {
                swaping_arr(p_w,j,j+1);
                swaping_arr(p,j,j+1);
                swaping_arr(w,j,j+1);
            }
        }
    }
   
}

float knapsack(float w[],float p[],int n,float W){
    sort(w,p,n);
    
    float x[n+1];
    for (int i = 1; i <= n; i++)
    {
        x[i]=0.0;
    }
    
    float u=W;
    
    for (int i = 1; i <=n ; i++)
    {
       if (w[i]>u)
       {
            x[i]=u/w[i];
            break;
       }
       else
       {
        x[i]=1.0;
        u=u-w[i];
       }
       //cout<<u<<endl;
       
    }
    display_float(x,n+1);
    float profit=0;
    for(int i = 1; i <=n; i++)
    {
        profit=profit+x[i]*p[i];
        //cout<<profit<<endl;
    }
    return profit;
    
}

int main()
{
    float w[8] = {0, 2, 3, 5, 7, 1, 4, 1};
    float p[8] = {0, 10, 5, 15, 7, 6, 18, 3};
    float profit=knapsack(w,p,7,15);
    display_float(p,8);
    display_float(w,8);
    cout<<profit;
    
    return 0;
}