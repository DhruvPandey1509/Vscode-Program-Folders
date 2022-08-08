#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isCovered(vector<vector<int>> &ranges, int left, int right)
    {

        unordered_map<int, int> m;
        for (int i = 0; i < ranges.size(); i++)
        {
            int st = ranges[i][0];
            int en = ranges[i][1];
            for (int j = st; j <= en; j++)
            {
                m[j]++;
            }
        }

        for (int i = left; i <= right; i++)
        {
            if (m.find(i) == m.end())
                return false;
        }

        return true;
    }
};