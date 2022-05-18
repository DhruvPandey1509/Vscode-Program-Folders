#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int>> m, int r, int c)
    {
        vector<int> res;

        int k = 0;
        int srow = 0;
        int scol = 0;

        int erow = r - 1;
        int ecol = c - 1;

        int total = r * c;

        while (k < total)
        {
            for (int i = scol; i <= ecol && k < total; i++)
            {
                res.push_back(m[srow][i]);
                k++;
            }
            srow++;
            for (int i = srow; i <= erow && k < total; i++)
            {
                res.push_back(m[i][ecol]);
                k++;
            }
            ecol--;

            for (int i = ecol; i >= scol && k < total; i--)
            {
                res.push_back(m[erow][i]);
                k++;
            }
            erow--;

            for (int i = erow; i >= srow && k < total; i--)
            {
                res.push_back(m[i][scol]);
                k++;
            }
            scol++;
        }

        return res;
    }
};