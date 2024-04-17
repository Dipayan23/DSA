
#include <iostream>
using namespace std;

void heapAdjust(int a[], int i, int n)
{
	int j = 2 * i;
	int key = a[i];
	while (j <= n)
	{
		if (j < n && a[j] < a[j + 1])
		{
			j++;
		}
		else
		{
			break;
		}
		a[j / 2] = a[j];
		j = 2 * j;
	}
	a[j / 2] = key;
}

void makeHeap(int a[],int n){
	for (int i = n/2;i>=1; i--)
	{
		heapAdjust(a,i,n);
	}
	
}

void heapSort(int a[],int n){
	makeHeap(a,n);
	for (int i = n; i>=1; i--)
	{
		int t=a[i];
		a[i]=a[1];
		a[1]=t;
		heapAdjust(a,1,i-1);
	}
	
}

int main()
{
	int a[6]={0,1,7,2,3,5};
	heapSort(a,5);
	for(int i=1;i<6;i++){
		cout<<a[i]<<" 	";
	}
}
