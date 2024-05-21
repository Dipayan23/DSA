#include <iostream>
using namespace std;

int max_min(int arr[],int i,int j,int *max,int *min){
    int max1,min1;
    if (i==j)
    {
        *max=*min=arr[i];
    }
    else if (i==j-1)
    {
        if (arr[i]<arr[j])
        {
            *max=arr[j];
            *min=arr[i];
        }
        else
        {
            *max=arr[i];
            *min=arr[j];
        }
        
    }
    else
    {
        int mid=(i+j)/2;
        max_min(arr,i,mid,max,min);
        max_min(arr,mid,j,&max1,&min1);
        if (max1>*max)
        {
            *max=max1;              
        }
        if (min1<*min)
        {
            *min=min1;
        }
    }
    //cout<<*max<<"    "<<*min<<endl;
    return (*max,*min);
}

int main(){
    int arr[6]={5,2,3,2,1,7};
    int max,min;
    max_min(arr,0,5,&max,&min);
    cout<<max<<endl<<min;
return 0;
}