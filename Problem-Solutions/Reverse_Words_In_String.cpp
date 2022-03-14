#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string word = "";
        string res;

        int wordSize = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ' && word.size() != 0)
            {
                st.push(word);
                word = "";
            }
            else if (s[i] == ' ' && word.size() == 0)
            {
                continue;
            }
            else
            {
                word += s[i];
            }
        }

        if (word.size() != 0)
        {
            st.push(word);
            word = "";
        }

        while (!st.empty())
        {
            string temp = st.top();
            res += temp + ' ';
            st.pop();
        }

        res.erase(res.size() - 1);

        return res;
    }
};