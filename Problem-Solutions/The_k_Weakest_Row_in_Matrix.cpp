#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        int row = mat.size();
        int col = mat[0].size();

        vector<pair<int, int>> v;
        vector<int> res;
        for (int i = 0; i < row; i++)
        {
            int ones = 0;
            for (int j = 0; j < col; j++)
            {
                if (mat[i][j] == 1)
                {
                    ones++;
                }
            }
            v.push_back({ones, i});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < k; i++)
        {
            res.push_back(v[i].second);
        }

        return res;
    }
};