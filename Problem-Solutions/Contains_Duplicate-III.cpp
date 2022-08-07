#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i], i});
        }
        sort(v.begin(), v.end());
        long long int T = t;
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = i + 1; j < v.size(); j++)
            {
                long long val = (long long)v[j].first - v[i].first;
                if (val <= T)
                {
                    if (abs(v[j].second - v[i].second) <= k)
                        return true;
                }
                else
                {
                    break;
                }
            }
        }

        return false;
    }
};