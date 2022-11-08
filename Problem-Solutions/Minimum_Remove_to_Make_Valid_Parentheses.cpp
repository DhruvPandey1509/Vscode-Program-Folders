#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int open = 0;
        string temp = "";
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                open++;
            else if (s[i] == ')')
            {
                if (open == 0)
                    continue;
                open--;
            }
            temp += s[i];
        }

        string res = "";
        for (int i = temp.size() - 1; i >= 0; i--)
        {
            if (temp[i] == '(' and open > 0)
            {
                open--;
                continue;
            }
            res += temp[i];
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
