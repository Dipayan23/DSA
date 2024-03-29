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
    void preOrderTraverse(Node *);
    void postOrderTraverse(Node *);
    void remove(int);
    bool search(int, Node *);
    int findSmall();
    int findBig();
    int totalNode(Node *);
    int height(Node *);
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

void BST ::inOrderTraverse(Node *root)
{
    if (root)
    {
        inOrderTraverse(root->lchild);
        cout << root->data << " ";
        inOrderTraverse(root->rchild);
    }
}

void BST ::preOrderTraverse(Node *root)
{
    if (root)
    {
        cout << root->data << " ";
        preOrderTraverse(root->rchild);
        preOrderTraverse(root->lchild);
    }
}

void BST ::postOrderTraverse(Node *root)
{
    if (root)
    {
        postOrderTraverse(root->lchild);
        postOrderTraverse(root->rchild);
        cout << root->data << " ";
    }
}

bool BST::search(int val, Node *root)
{
    if (root)
    {

        if (root->data == val)
        {
            return true;
        }
        else if (root->data > val)
        {
            return search(val, root->lchild);
        }
        else
        {
            return search(val, root->rchild);
        }
    }
    else
    {
        return false;
    }
}

int BST ::findBig()
{
    Node *temp = root;
    while (temp->rchild)
    {
        temp = temp->rchild;
    }
    return temp->data;
}

int BST ::findSmall()
{
    Node *temp = root;
    while (temp->lchild)
    {
        temp = temp->lchild;
    }
    return temp->data;
}

int BST::totalNode(Node *root)
{
    if (root)
    {
        return totalNode(root->lchild) + totalNode(root->rchild) + 1;
    }
    else
    {
        return 0;
    }
}

int BST ::height(Node *root)
{
    if (root)
    {
        int n1 = height(root->lchild) + 1;
        int n2 = height(root->rchild) + 1;
        if (n1 > n2)
        {
            return n1;
        }
        else
        {
            return n2;
        }
    }
    else
    {
        return 0;
    }
}

void BST::remove(int key)
{
    if (root == NULL)
    {
        cout << "The BST is empty" << endl;
        return;
    }
    Node *x = root;
    Node *par = NULL;
    while (x != NULL && x->data != key)
    {
        par = x;
        if (x->data > key)
        {
            x = x->lchild;
        }
        else
        {
            x = x->rchild;
        }
    }
    if (x == NULL)
    {
        cout << "The element is not found" << endl;
        return;
    }
    if (!x->lchild || !x->rchild)
    {
        Node *ptr;
        if (!x->lchild)
            ptr = x->rchild;
        else
            ptr = x->rchild;
        if (!par)
        {
            delete root;
            root = ptr;
            return;
        }
        if (x == par->lchild)
            par->lchild = ptr;
        else
            par->rchild = ptr;
        return;
    }

    else
    {
        Node *succ = x->rchild;
        Node *par2 = NULL;
        while (succ->lchild != NULL)
        {
            par2 = succ;
            succ = succ->lchild;
        }
        x->data = succ->data;
        par2->lchild = succ->lchild;
        delete succ;
        return;
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
    S.insert(8);
    S.insert(2);
    S.inOrderTraverse(S.getRoot());
    cout << endl;
    S.remove(1);
    S.inOrderTraverse(S.getRoot());
    return 0;
}