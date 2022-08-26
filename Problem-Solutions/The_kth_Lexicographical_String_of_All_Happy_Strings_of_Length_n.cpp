#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<char> v = {'a', 'b', 'c'};
    vector<string> res;

    void helper(string s, int n, char prev)
    {
        if (n == 0)
        {
            res.push_back(s);
            return;
        }

        for (int i = 0; i < v.size(); i++)
        {
            if (prev != v[i])
            {
                s.push_back(v[i]);
                helper(s, n - 1, v[i]);
                s.pop_back();
            }
        }
    }

    string getHappyString(int n, int k)
    {

        string s = "";
        helper(s, n, '#');

        if (res.size() < k)
        {
            return "";
        }
        return res[k - 1];
    }
};
