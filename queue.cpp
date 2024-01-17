#include <iostream>
using namespace std;

class Queue
{
    static const int MAX = 100;
    int arr[MAX];
    int front;
    int rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }
    void enQueue(int s);
    void deQueue();
    int peek();
    bool isEmpty();
    bool isFull();
    int getSize();
};

void Queue ::enQueue(int s)
{
    if (isFull())
    {
        cout << "The Queue is Full" << endl;
    }
    else
    {
        arr[++rear] = s;
    }
}

void Queue ::deQueue()
{
    if (isEmpty())
    {
        cout << "The Queue is Empty" << endl;
    }
    else
    {
        front++;
    }
}

int Queue ::peek()
{
    if (isEmpty())
    {
        cout << "The Queue is Empty" << endl;
        return -1;
    }
    else
    {
        return arr[front + 1];
    }
}

bool Queue ::isEmpty()
{
    return rear == -1;
}

bool Queue ::isFull()
{
    return rear == MAX - 1;
}

int Queue ::getSize()
{
    return (rear - front + 1);
}

int main()
{
    Queue Q;
    Q.enQueue(3);
    Q.enQueue(5);
    Q.enQueue(2);
    cout<<Q.peek()<<endl;
    Q.deQueue();
    cout<<Q.peek();
    return 0;
}