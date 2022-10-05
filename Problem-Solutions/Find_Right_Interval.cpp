#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool comp(const vector<int> &a, const vector<int> &b)
    {
        return a[0] <= b[0];
    }

    vector<int> findRightInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<int> res(n);
        if (n == 0)
            return res;

        for (int i = 0; i < n; i++)
        {
            res[i] = intervals[i][1];
            intervals[i][1] = i;
        }
        sort(intervals.begin(), intervals.end(), comp);

        for (int i = 0; i < n; i++)
        {
            int end = res[i];

            int l = 0, r = n - 1, mid, resI = -1;
            while (l <= r)
            {
                mid = l + (r - l) / 2;
                if (intervals[mid][0] >= end)
                {
                    resI = intervals[mid][1];
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            res[i] = resI;
        }
        return res;
    }
};