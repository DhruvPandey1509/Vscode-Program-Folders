#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string thousandSeparator(int n)
    {

        stack<char> st;

        string s = to_string(n);
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if (count != 0 and count % 3 == 0)
            {
                st.push('.');
            }
            count++;
            st.push(s[i]);
        }
        string res = "";
        while (!st.empty())
        {
            res = res + st.top();
            st.pop();
        }

        return res;
    }
};