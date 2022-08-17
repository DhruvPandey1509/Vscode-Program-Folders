#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string removeKdigits(string num, int k)
    {
        if (num.size() == k)
            return "0";

        // maintain an increasing sequence of characters
        string st; // stack : using monotonic Stack concept
        for (int i = 0; i < num.size(); i++)
        {
            // if the current digit is greater than the stack top
            // we will pop the stack till either the stack top becomes
            // less than or equal to the current digit or we have removed k
            // digits
            while (st.size() and st.back() > num[i] and k)
            {
                st.pop_back();
                k--;
            }
            st.push_back(num[i]);
        }

        // if any digits have to be removed, remove them from the back as they
        // are the largest ones
        if (k > 0)
        {
            while (k > 0)
            {
                st.pop_back();
                k--;
            }
        }
        // removing the leading 0s if any;

        int non_zero_idx = -1;
        for (int i = 0; i < st.size(); i++)
        {
            if (st[i] != '0')
            {
                non_zero_idx = i;
                break;
            }
        }

        // all number are 0
        if (non_zero_idx == -1)
        {
            return "0";
        }

        // first non zero number is at index non_zero_idx
        return st.substr(non_zero_idx, st.size() - non_zero_idx);
    }
};