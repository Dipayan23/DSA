#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Linklist
{
public:
    Node *head;

    Linklist()
    {
        head = NULL;
    }
    void inBeg(int data);
    void inEnd(int data);
    void delBeg();
    void delEnd();
    void display();
};

void Linklist ::inBeg(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void Linklist ::inEnd(int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *curr = head;

        while (curr->next)
        {
            curr = curr->next;
        }
        curr->next = newNode;
        cout<<"DONE";
    }
}

void Linklist ::delBeg()
{
    if (!head)
    {
        cout << "The the List is Empty" << endl;
    }
    else if (!head->next)
    {
        head = NULL;
    }

    else
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void Linklist::delEnd()
{
    if (!head)
    {
        cout << "The the List is Empty" << endl;
    }
    else if (!head->next)
    {
        head = NULL;
    }

    else
    {
        Node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void Linklist ::display()
{
    if (!head)
    {
        cout << "The the List is Empty" << endl;
    }
    else
    {
        Node *curr = head;
        while (curr)
        {

            cout << curr->data << " ";
            curr = curr->next;
        }
    }
}

int main()
{
    Linklist L;
    L.inBeg(3);
    L.inBeg(6);
    L.inEnd(9);
    L.display();
    L.delBeg();
    L.display();
    return 0;
}