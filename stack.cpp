#include <iostream>
using namespace std;
class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    };
    void push(int value);
    void pop();
    int peek();
    bool isEmpty();
    bool isFull();
    int getSize();
};

void Stack :: push(int value){
    if (isFull())
    {
        cout<<"Stack Overflow"<<endl;
        return;
    }
    arr[++top]=value;
}
void Stack :: pop(){
    if (isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
        return;
    }
    top--;
}
int Stack :: peek(){
    return arr[top];
}
bool Stack :: isEmpty(){
    return (top<=-1);
}

bool Stack :: isFull(){
    return (top>=100);
}

int Stack :: getSize(){
    return (top+1);
}

int main()
{
    Stack S;
    S.push(3);
    S.push(5);
    S.push(1);
    cout<<S.peek();
    S.pop();
    cout<<S.peek();
    return 0;
}