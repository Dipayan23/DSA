#include <iostream>
using namespace std;

class Node{
public:
    int data;
    int pri;
    Node *next;
    Node(int data){
        this->data=data;
        pri=100000;
    }
};

class priority_Queue{
    Node *head;
public:
    priority_Queue(){
        head=NULL;
    }
    void insert(int ,int );
    void del();
    void display();

};

void priority_Queue :: insert(int val,int p){
    Node *newNode = new Node(val);
    newNode->pri=p;
    if (head==NULL)
    {
        head=newNode;
        
    }
    else if (newNode->pri<head->pri)
    {
        newNode->next=head;
        head=newNode;
        
    }

    else{
        Node *temp=head;
        while (temp->next&&(temp->next->pri<newNode->pri))
        {
            temp=temp->next;
        }
        newNode->next=temp->next;
        temp->next=newNode;
        
    }
    
}

void priority_Queue :: display(){
    if (head==NULL)
    {
        cout<<"The queue is empty"<<endl;
        return;
    }
    Node *temp=head;
    while (temp)
    {
        cout<<"["<<temp->data<<","<<temp->pri<<"]"<<" ";
        temp=temp->next;
    }
    
}

int main(){
    priority_Queue S;
    S.insert(3,2);
    S.insert(5,1);
    S.insert(7,9);
    S.insert(9,7);
    S.insert(1,4);
    S.display();
return 0;
}