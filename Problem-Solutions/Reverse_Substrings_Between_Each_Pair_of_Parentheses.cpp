#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string reverseParentheses(string s)
    {
        stack<char> st;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ')')
            {
                string a = "";
                while (st.top() != '(')
                {
                    a += st.top();
                    st.pop();
                }
                st.pop();

                for (int i = 0; i < a.size(); i++)
                {
                    st.push(a[i]);
                }
            }
            else
            {
                st.push(s[i]);
            }
        }

        string res = "";

        while (!st.empty())
        {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
