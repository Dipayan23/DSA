#include <iostream>
using namespace std;

int arr[100];
int n=0;

void insert(int a[],int n,int key){
    n++;
    a[n]=key;
    int i=n;
    while (i>1)
    {
        int parent =(i/2);
        if (a[parent]<a[i])
        {
            swap(a[parent],a[i]);
            i=parent;
        }
        else
        {
            return;
        }
    }
    
}

void deleatetion(int a[],int n){
    a[1]=a[n];
    n=n-1;
    int i=1;
    while(i<n){
        int left=a[2*i];
        int right =a[2*i+1];
        int large = left<right?2*i+1:2*i;
        if (a[large]>a[i])
        {
            swap(a[i],a[large]);
        }
        i=large;
    }
}

void heapify(int a[],int n ,int i){
    int largest=i;
    int left=2*i;
    int right = 2*i+1;
    if (left<=n && a[left]>a[largest])
    {
        largest=left;
    }
    if (right<=n&& a[right]>a[largest])
    {
        largest=right;
    }
    if (largest!=i)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

void makeHeap(int a[],int n){
    for (int i = n/2; i >0; i--)
    {
        heapify(a,n,i);
    }
}

void heapSort(int a[],int n){
    makeHeap(a,n);
    for (int i = n; i > 1; i--)
    {
        swap(a[1],a[i]);
        heapify(a,i-1,1);
    }
    
}

int main(){
    int a[7]={0,2,4,9,1,3,7};
    heapSort(a,6);
    for (int i = 1; i < 7; i++)
    {
        cout<<a[i]<<" ";
    }
return 0;
}