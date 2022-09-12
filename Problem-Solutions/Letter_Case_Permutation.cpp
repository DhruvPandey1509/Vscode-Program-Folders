#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> res;
    void solve(string curr, string s, int i)
    {
        if (i == s.size())
        {
            res.push_back(curr);
            return;
        }

        if (isdigit(s[i]))
        {
            curr.push_back(s[i]);
            solve(curr, s, i + 1);
        }

        else
        {
            string c1 = curr;
            c1.push_back(tolower(s[i]));
            solve(c1, s, i + 1);

            string c2 = curr;
            c2.push_back(toupper(s[i]));
            solve(c2, s, i + 1);
        }
    }
    vector<string> letterCasePermutation(string s)
    {
        solve("", s, 0);
        return res;
    }
};