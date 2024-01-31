#include <iostream>
using namespace std;
class Array
{
private:
    int arr[100];
    int len;

public:
    Array();
    void insert(int, int);
    void remove(int);
    int search(int);
    void update(int, int);
    void display();
};
Array::Array(/* args */)
{
    len = 0;
}

void Array::insert(int k, int x)
{
    if (k > len)
    {
        cout << "The index is invalid" << endl;
    }
    else if (k == len)
    {
        arr[len] = x;
        len++;
    }
    else
    {
        for (int i = len; i > k; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[k] = x;
    }
}

void Array ::display()
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void Array ::remove(int x)
{
    if (len == 0)
    {
        cout << "The array is empty" << endl;
    }
    else
    {
        if (search(x) != -1)
        {
            for (int i = search(x); i < len - 1; i++)
            {
                arr[i] = arr[i + 1];
            }
            len--;
        }
        else
        {
            cout << "The data is not found" << endl;
        }
    }
}

void Array::update(int k,int x){
    arr[k]=x;
}

int Array::search(int x)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == x)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    Array Arr;
    int choice = 0, n, k;
    do
    {

        cout << "MENU" << endl
             << "1.insert" << endl
             << "2.Remove" << endl
             << "3.update" << endl
             << "4.Search" << endl
             << "5.Display"
             << "6.Exit" << endl
             << "Enter the choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the index :";
            cin >> k;
            cout << endl
                 << "Enter the data :";
            cin >> n;
            Arr.insert(k, n);
            break;
        case 2:
            cout << endl
                 << "Enter the data :";
            cin >> n;
            Arr.remove(n);
            break;
        case 3:
            cout << "Enter the index :";
            cin >> k;
            cout << endl
                 << "Enter the data :";
            cin >> n;
            Arr.update(k, n);
            break;
        case 4:
            cout << endl
                 << "Enter the data :";
            cin >> n;
            cout<<"Ihe index "<<Arr.search(n)<<endl;
            break;
        case 5:
            Arr.display();
            break;
        case 6:
            break;

        default:
            cout << "Invalid choice pleace try again" << endl;
            break;
        }

    } while (choice != 6);
    return 0;
}