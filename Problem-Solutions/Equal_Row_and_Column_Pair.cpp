#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int equalPairs(vector<vector<int>> &grid)
    {
        map<vector<int>, int> m;
        for (int i = 0; i < grid.size(); i++)
        {
            m[grid[i]]++;
        }

        int count = 0;
        vector<int> temp;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                temp.push_back(grid[j][i]);
            }

            if (m.find(temp) != m.end())
            {
                count += m[temp];
            }
            temp.clear();
        }

        return count;
    }
};