#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> m;
        int x = accumulate(wall[0].begin(), wall[0].end(), 0);
        for (auto i : wall)
        {
            int sum = 0;
            for (int brick : i)
            {
                sum += brick;
                if (sum < x)
                {
                    m[sum]++;
                }
            }
        }

        int max_num = 0;
        for (auto i : m)
        {
            max_num = max(max_num, i.second);
        }
        return wall.size() - max_num;
    }
};