#include <iostream>
using namespace std;

void heapfy(int arr[], int n, int i)
{
    int largest = i;
    int l = (2 * i) + 1;
    int r = (2 * i) + 2;
    if (l < n && arr[l] > arr[i])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapfy(arr, n, largest);
    }
}

void built_heap(int arr[], int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        heapfy(arr, n, i);
    }
}

void heap_sort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        heapfy(arr, i, 0);
    }
}

int main()
{

    int arr[8] = {5, 2, 9, 1, 3, 5, 8, 4};
    heap_sort(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}