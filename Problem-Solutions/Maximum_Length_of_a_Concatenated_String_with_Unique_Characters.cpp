#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int res = 0;
    bool isUnique(string s)
    {
        unordered_map<char, int> m;
        for (char c : s)
        {
            if (m.find(c) != m.end())
                return false;
            m[c]++;
        }
        return true;
    }
    void backtrack(vector<string> &v, int i, int n, string curr)
    {
        if (!isUnique(curr))
            return;
        if (i == n)
        {
            int len = curr.size();
            if (len > res)
            {
                res = len;
            }
            return;
        }

        backtrack(v, i + 1, n, curr + v[i]);
        backtrack(v, i + 1, n, curr);
    }
    int maxLength(vector<string> &arr)
    {
        int n = arr.size();
        backtrack(arr, 0, n, "");
        return res;
    }
};
