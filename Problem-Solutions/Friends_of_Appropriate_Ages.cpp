#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numFriendRequests(vector<int> &ages)
    {
        int res = 0;
        sort(ages.begin(), ages.end());
        unordered_map<int, int> m;
        for (int i = 0; i < ages.size(); i++)
        {
            if (m.find(ages[i]) == m.end())
            {
                m[ages[i]] = i;
            }
        }

        for (int i = 0; i < ages.size(); i++)
        {
            int x = lower_bound(ages.begin(), ages.end(), 2 * (ages[i] - 7)) - ages.begin();
            if (x <= i)
            {
                continue;
            }

            res += x - m[ages[i]] - 1;
        }
        return res;
    }
};