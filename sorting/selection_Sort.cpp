#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void input_Array(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
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

void selection_Sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(arr[min], arr[i]);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    input_Array(a, n);
    display(a, n);
    selection_Sort(a, n);
    cout << endl;
    display(a, n);
    return 0;
}
