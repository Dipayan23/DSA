#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    int height;
    Node(int data)
    {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
        height = 1;
    }
};

class AVL{
    Node* root;
public:
    AVL(){
        root=NULL;
    }
    void insert(int);
};



int main()
{

    return 0;
}