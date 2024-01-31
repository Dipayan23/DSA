#include <iostream>
using namespace std;

class Node
{
public:
    int coe;
    int pow;
    Node *next;
};
class Poly
{
private:
    /* data */
    Node *head;

public:
    Poly(/* args */);
    void insert(int, int);
    void display();
    Poly operator+(Poly &p);
};

Poly::Poly(/* args */)
{
    head = NULL;
}
void Poly::insert(int c, int p)
{
    Node *temp = new Node;
    temp->coe = c;
    temp->pow = p;
    temp->next = NULL;
    if (!head)
    {
        head = temp;
    }
    else if (head->pow < temp->pow)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        Node *curr = head;
        Node *par = NULL;
        while (curr->next && curr->pow >= temp->pow)
        {
            par = curr;
            curr = curr->next;
        }
        if (temp->pow == curr->pow)
        {
            temp->coe = (temp->coe) + (curr->coe);
            return;
        }
        else if (curr->pow < temp->pow)
        {
            temp->next = curr;
            par->next = temp;
        }
        else
        {
            curr->next = temp;
        }
    }
}

void Poly ::display()
{
    Node *curr = head;
    if (!head)
    {
        cout << "0" << endl;
    }
    else
    {
        while (curr->next)
        {
            cout << curr->coe << "x^" << curr->pow;
            if (curr->coe >= 0)
            {
                cout << "+";
            }
            curr = curr->next;
        }
        cout << curr->coe << "x^" << curr->pow;
    }
}

Poly Poly ::operator+(Poly &p)
{
    Node *h1 = head;
    Node *h2 = p.head;
    Poly result;
    while (h1 && h2)
    {
        if (h1->pow > h2->pow)
        {
            result.insert(h1->coe, h1->pow);
            h1 = h1->next;
        }
        else if (h1->pow < h2->pow)
        {
            result.insert(h2->coe, h2->pow);
            h2 = h2->next;
        }
        else
        {
            result.insert((h1->coe + h2->coe), (h1->pow + h2->pow));
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    if (h1)
    {
        result.insert(h1->coe, h1->pow);
        h1 = h1->next;
    }
    else
    {
        result.insert(h2->coe, h2->pow);
    }

    return result;
}

int main()
{
    Poly p1, p2, p3;
    p1.insert(3, 5);
    p1.insert(3, 6);
    p1.insert(3, 2);
    p1.display();
    cout << endl;

    p2.insert(6, 4);
    p2.insert(3, 6);
    p2.insert(3, 0);
    p2.display();
    cout << endl;

    p3 = p1 + p2;
    p3.display();

    return 0;
}