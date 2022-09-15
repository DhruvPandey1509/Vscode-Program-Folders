#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<string>> res;
    bool isPalindrome(string s, int st, int en)
    {
        while (st <= en)
        {
            if (s[st] != s[en])
                return false;

            st++;
            en--;
        }
        return true;
    }

    void makePartition(vector<string> v, string s, int start)
    {
        if (start == s.length())
        {
            res.push_back(v);
            return;
        }

        for (int i = start; i < s.size(); i++)
        {
            if (isPalindrome(s, start, i))
            {
                v.push_back(s.substr(start, i - start + 1));
                makePartition(v, s, i + 1);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<string> v;
        makePartition(v, s, 0);
        return res;
    }
};