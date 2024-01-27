#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *lchild;
    Node *rchild;
    Node(int data)
    {
        this->data = data;
        lchild = NULL;
        rchild = NULL;
    }
};

class BST
{
    Node *root;
public:
    BST()
    {
        root = NULL;
    }
    void insert(int);
    void inOrderTraverse(Node *);
    void preOrderTraverse();
    void postOrderTraverse();
    void remove();
    bool search(int);
    int findSmall();
    int findBig();
    int totalNode();
    int height();
    Node *getRoot();
};

Node *BST::getRoot()
{
    return root;
}

void BST ::insert(int val)
{
    Node *newNode = new Node(val);
    if (root == NULL)
    {
        root = newNode;
    }
    else
    {
        Node *temp = root;
        Node *parent = NULL;
        while (temp)
        {
            parent = temp;
            if (temp->data > newNode->data)
            {
                temp = temp->lchild;
            }
            else
            {
                temp = temp->rchild;
            }
        }
        if (parent->data > newNode->data)
        {
            parent->lchild = newNode;
        }
        else
        {
            parent->rchild = newNode;
        }
    }
}

void BST :: inOrderTraverse(Node *root)
{
    if (root)
    {
        inOrderTraverse(root->lchild);
        cout << root->data << " ";
        inOrderTraverse(root->rchild);
    }
}

int main()
{
    BST S;
    S.insert(5);
    S.insert(1);
    S.insert(7);
    S.insert(9);
    S.insert(3);
    S.insert(6);
    S.inOrderTraverse(S.getRoot());
    return 0;
}