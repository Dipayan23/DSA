#include <iostream>
using namespace std;



int fib(int n,int dp[]){
    if (n==0)
    {
        return 0;
    }
    if (n==1)
    {
        return 1;
    }
    if (dp[n]!=0)
    {
        return dp[n];
    }
    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main(){
    int dp[100]={0};
    cout<<fib(20,dp);
return 0;
}