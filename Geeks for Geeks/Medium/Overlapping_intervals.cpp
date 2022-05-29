#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {

        if (intervals.size() == 0)
        {
            return intervals;
        }

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        res.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++)
        {
            if (intervals[i][0] <= res[res.size() - 1][1] && intervals[i][1] > res[res.size() - 1][1])
            {
                int x = res[res.size() - 1][0];
                int y = res[res.size() - 1][1];
                res.pop_back();
                res.push_back({min(x, intervals[i][0]), max(intervals[i][1], y)});
            }
            else if (intervals[i][0] > res[res.size() - 1][1])
            {
                res.push_back(intervals[i]);
            }
        }

        return res;
    }
};