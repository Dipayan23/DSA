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

void bubble_Sort(int arr[], int n)
{

    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)

            if (arr[j] > arr[j + 1])

                swap(arr[j], arr[j + 1]);
}

int display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    input_Array(a,n);
    display(a,n);
    bubble_Sort(a,n);
    cout<<endl;
    display(a,n);
    return 0;
}