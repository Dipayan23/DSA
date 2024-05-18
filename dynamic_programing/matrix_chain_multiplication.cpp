#include <iostream>
using namespace std;

void display(int arr[][5],int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

int matrix_chain(int arr[],int n){
    int dp[5][5];
    int s[5][5];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j]=9999;
            s[i][j]=-1;
        }
        
    }
    
    for (int i = 0; i < n; i++)
    {
        dp[i][i]=0;
    }
    for (int len = 2; len < n; len++)
    {
        for (int i = 1; i < n-len+1; i++)
        {
            int j=i+len-1;
            dp[i][j]=9999;
            for (int k = i; k <j; k++)
            {
                int cost=dp[i][k]+dp[k+1][j]+(arr[i-1]*arr[k]*arr[j]);
                if (cost<dp[i][j])
                {
                    dp[i][j]=cost;
                    s[i][j]=k;
                }
                
            }
            
        }
        
    }
    display(dp,n);
    display(s,n);
    return dp[1][n-1];

}

int main(){
    int arr[5]={2,3,4,1,3};
    cout<<matrix_chain(arr,5);
return 0;
}