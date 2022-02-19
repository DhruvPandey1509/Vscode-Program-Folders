#include <iostream>
#include <stack>

using namespace std;

string infixToPostfix(string s);
int prec(char c);

int main()
{
    cout<<infixToPostfix("(a-b/c)*(a/k-l)")<<endl;
    return 0;
}
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    if (c == '*' || c == '/')
    {
        return 2;
    }
    if (c == '+' || c == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
string infixToPostfix(string s)
{
    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!s.empty() && st.top() != '(')
            {
                res += st.top();
                st.pop();
            }
            if (!s.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.top()) > prec(s[i]))
            {
                res += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }

    return res;
}
