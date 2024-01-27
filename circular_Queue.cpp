#include <iostream>
using namespace std;

class circular_Queue
{
private:
    int rear, front;
    int size;
    int *arr;

public:
    circular_Queue(int);
    void enQueue(int);
    void display();
    void deQueue();
};

circular_Queue::circular_Queue(int s)
{
    size = s;
    front = rear = -1;
    arr = new int[s];
}

void circular_Queue ::enQueue(int data)
{
    if ((front == 0 && rear == size - 1) || (rear + 1 == front))
    {
        cout << "The Queue is full" << endl;
    }
    else if (front == -1)
    {
        front++;
        rear++;
        arr[front] = data;
    }
    else if (rear == size - 1)
    {
        rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear++;
        arr[rear] = data;
    }
}

void circular_Queue ::display()
{
    if (front == -1)
    {
        cout << "The Queue is empty" << endl;
    }
    else if (front <= rear)
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    else
    {
        for (int i = front; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void circular_Queue ::deQueue()
{
    if (front == -1)
    {
        cout << "The Queue is empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
}

int main()
{
    circular_Queue S(5);
    S.enQueue(5);
    S.enQueue(4);
    S.enQueue(2);
    S.enQueue(7);
    S.enQueue(1);
    S.enQueue(9);
    S.display();
    S.deQueue();
    S.deQueue();
    S.display();
    S.enQueue(4);
    S.display();
    return 0;
}