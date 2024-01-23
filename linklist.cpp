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
    bool search(int value);
    void bubbleSort();
    void count();
    void sum();
    void max();
    Node* getHead();
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
        cout << "DONE";
    }
}

Node* Linklist :: getHead(){
    return head;
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

void merge(Linklist p,Linklist q){
    Node* head1=p.getHead();
    Node* head2 = q.getHead();
    Node* last = NULL;
    Node* temp= NULL;
    if (head1->data<head2->data)
    {
        temp=last=head1;
        head1=head1->next;
        last->next=NULL;
    }
    else
    {
        temp=last=head2;
        head2=head2->next;
        last->next=NULL;
    }
    while (head1&&head2)
    {
        if (head1->data<head2->data)
        {
            last->next=head1;
            last=head1;
            head1=head1->next;
            last->next=NULL;
        }
        else
        {
            last->next=head2;
            last=head2;
            head2=head2->next;
            last->next=NULL;
        }
        if (head1)
        {
            last->next=head1;
        }
        else
        {
            last->next=head2;
        }
        
        
    }
    
}

void concat(Linklist p,Linklist q){
    Node* curr = p.getHead();
    while (curr->next)
    {
        curr=curr->next;
    }
    curr->next=q.getHead();
    
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

bool Linklist ::search(int value)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void Linklist ::bubbleSort()
{
    if (head == NULL)
    {
        return;
    }
    int swapped;
    Node *current;
    Node *last = NULL;
    do
    {
        swapped = 0;
        current = head;
        while (current->next != last)
        {
            if (current->data > current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = 1;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}
void Linklist ::inBeg(int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
    cout << "The value is inserted" << endl;
}

void Linklist :: count(){
    int count=0;
    Node* temp = head;
    while (temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    cout<<"The total no of nodes are :"<<count<<endl;
}

void Linklist :: sum(){
    int sum=0;
    Node* temp = head;
    while (temp!=NULL)
    {
        sum+=temp->data;
        temp=temp->next;
    }
    cout<<"The sum is :"<<sum<<endl;
}

void Linklist :: max(){
    int max=INT32_MIN;
    Node* temp = head;
    while (temp!=NULL)
    {
        if (max<temp->data)
        {
            max=temp->data;
        }
        temp=temp->next;
    }
    cout<<"The largest element is :"<<max<<endl;
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