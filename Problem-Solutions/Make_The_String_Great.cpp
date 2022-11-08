#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    string makeGood(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (!st.empty() && ((st.top() - 'a' == s[i] - 'A') || (st.top() - 'A' == s[i] - 'a')))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        s.clear();
        while (!st.empty())
        {
            s += st.top();
            st.pop();
        }
        reverse(s.begin(), s.end());
        return s;
    }
};