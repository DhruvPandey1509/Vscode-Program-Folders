#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &inter)
    {

        if (inter.size() == 0)
        {
            return inter;
        }

        sort(inter.begin(), inter.end());

        vector<vector<int>> res;
        res.push_back(inter[0]);

        int n = inter.size();

        for (int i = 1; i < n; i++)
        {
            if (inter[i][0] <= res[res.size() - 1][1] && inter[i][1] >= res[res.size() - 1][1])
            {
                int x = res[res.size() - 1][0];
                int y = res[res.size() - 1][1];
                res.pop_back();
                res.push_back({min(x, inter[i][0]), max(y, inter[i][1])});
            }
            else if (inter[i][0] > res[res.size() - 1][1])
            {
                res.push_back(inter[i]);
            }
        }

        return res;
    }
};