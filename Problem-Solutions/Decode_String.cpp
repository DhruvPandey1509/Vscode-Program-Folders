#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<char> st;

        for (char c : s)
        {
            if (c != ']')
                st.push(c);
            else
            {
                string curr = "";

                while (st.top() != '[')
                {
                    curr = st.top() + curr;
                    st.pop();
                }
                st.pop(); // popping '['
                string digits = "";

                while (!st.empty() and isdigit(st.top()))
                {
                    digits = st.top() + digits;
                    st.pop();
                }

                int num = stoi(digits); // converting string num to int
                while (num--)
                {
                    for (char ch : curr)
                    {
                        st.push(ch);
                    }
                }
            }
        }

        s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};