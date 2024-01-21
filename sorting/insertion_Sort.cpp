#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void input_Array(int a[],int n){
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    
}

int display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertion_Sort(int arr[],int n){
    for (int i = 1; i < n; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    input_Array(a,n);
    display(a,n);
    insertion_Sort(a,n);
    cout<<endl;
    display(a,n);
    return 0;
}