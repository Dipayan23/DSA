#include <iostream>
using namespace std;

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;

}

int partition(int arr[],int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for (int j = l; j < r-1; j++)
    {
        if (pivot>arr[j])
        {
            i++;
            swap(arr[i],arr[j]);
        }
        
        
    }
    swap(arr[i+1],arr[r]);
    return i+1;
    
}

void quick_Sort(int arr[],int l,int r){
    if (l<r)
    {
        int pi = partition(arr,l,r);

        quick_Sort(arr,l,pi-1);
        quick_Sort(arr,pi+1,r);
    }
    
}

int main(){
     int arr[5]={4,7,1,9,2};
    quick_Sort(arr,0,4);
    for (int i = 0; i < 5; i++)
    {
        cout<<arr[i];
    }
return 0;
}