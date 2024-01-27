#include <iostream>
using namespace std;

// Linear Search

int linear_Search(int arr[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

// Binary Search

int binary_Search(int arr[], int l, int r, int x)
{
    if (l <= r)
    {

        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] > x)
        {
            return binary_Search(arr, l, mid - 1, x);
        }
        else
        {
            return binary_Search(arr, mid + 1, r, x);
        }
    }
    else{
        return -1;
    }
}

int main()
{
    int arr[6] = {1, 2, 4, 6, 8, 9};
    cout << binary_Search(arr, 0, 5, 14);
    return 0;
}