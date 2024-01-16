#include <iostream>
using namespace std;
#include <stack>

int precedence(char a)
{
    if (a == '^')
    {
        return 3;
    }
    if (a == '*' || a == '/')
    {
        return 2;
    }
    if (a == '+' || a == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

bool isOperend(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

string intopostfix(string s)
{
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];
        if (isOperend(c))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && precedence(s[i]) < precedence(st.top()) )
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }


        
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main()
{
    string infix="4+7+3/2*7*(3+6)";
    cout<<intopostfix(infix);
    return 0;
}