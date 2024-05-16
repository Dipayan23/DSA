#include <iostream>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l-1;
    int j = r + 1;
    while (true)
    {
        do
        {
            i++;
        } while (arr[i] < pivot);
        do
        {
            j--;
        } while (arr[j] > pivot);
        if (i >= j)
        {
            return j;
        }
        swap(arr[i], arr[j]);
    }
}

void quick_Sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition(arr, l, r);

        quick_Sort(arr, l, p);
        quick_Sort(arr, p+1, r);
        return;
    }
}

int main()
{
    int a[6] = {6, 2, 4, 1, 8, 9};
    quick_Sort(a, 0, 5);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << "   ";
    }

    return 0;
}