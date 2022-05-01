#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        priority_queue<int, vector<int>, greater<int>> p;

        int r = matrix.size();
        int c = matrix[0].size();

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                p.push(matrix[i][j]);
            }
        }

        for (int i = 0; i < k - 1; i++)
        {
            p.pop();
        }

        return p.top();
    }
};