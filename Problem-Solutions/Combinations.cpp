#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> res;
    vector<int> v;
    void helper(int start, int k, int n)
    {
        if (v.size() == k)
        {
            res.push_back(v);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            v.push_back(i);
            helper(i + 1, k, n);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {

        helper(1, k, n);
        return res;
    }
};