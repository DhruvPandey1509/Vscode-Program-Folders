#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
    vector<int> filterRestaurants(vector<vector<int>> &restaurants, int veganFriendly, int maxPrice, int maxDistance)
    {

        vector<pair<int, int>> v;

        int n = restaurants.size();
        for (auto r : restaurants)
        {
            if (veganFriendly)
            {
                if (r[2] == true)
                {
                    if (r[3] <= maxPrice and r[4] <= maxDistance)
                    {
                        v.push_back({r[0], r[1]});
                    }
                }
            }
            else
            {
                if (r[3] <= maxPrice and r[4] <= maxDistance)
                {
                    v.push_back({r[0], r[1]});
                }
            }
        }
        sort(v.begin(), v.end(), cmp);
        vector<int> res;
        for (auto p : v)
        {
            res.push_back(p.first);
        }

        return res;
    }
};
