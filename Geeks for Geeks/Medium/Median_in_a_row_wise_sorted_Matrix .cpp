#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int median(vector<vector<int>> &m, int r, int c)
    {
        priority_queue<int> p;

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                p.push(m[i][j]);
            }
        }

        int count = ((r * c) + 1) / 2 - 1;

        while (count--)
        {
            p.pop();
        }

        return p.top();
    }
};
