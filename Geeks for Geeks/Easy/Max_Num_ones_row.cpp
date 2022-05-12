#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxOnes(vector<vector<int>> &mat, int n, int m)
    {
        vector<pair<int, int>> v; // first = index, second = no. of ones
        int res = -1;
        int maxOne = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 1)
                {
                    if (m - j > maxOne)
                    {
                        maxOne = m - j;
                        res = i;
                    }
                }
            }
        }

        return res;
    }
};