#include <iostream>
using namespace std;
#include <stack>

int postfix_eval(string post){
    stack<int> st;
    for (int i = 0; i < post.length(); i++)
    {
        char c=post[i];
        if (i==0&&(c>='1'&&c<='9')!=1)
        {
            cout<<"Invalid exprassion"<<endl;
            return -1;
        }
        if (c>='1'&&c<='9')
        {
            st.push(c-48);
        }
        else
        {
            int op2=st.top();
            st.pop();
            int op1 = st.top();
            st.pop();
            if (c=='+')
            {
                st.push(op1+op2);
                
            }
            else if (c=='-')
            {
                st.push(op1-op2);
            }
            else if (c=='/')
            {
                st.push(op1/op2);
            }
            else if (c=='*')
            {
                st.push(op1*op2);
            }
            else
            {
                cout<<"Invalid Index";
                return -1;
            }
            
        }
        
       
    }
    return st.top();
}

int main(){
    string input="3478/*96/++";
    cout<<postfix_eval(input);
return 0;
}