#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    int earliestFullBloom(vector<int> &plantTime, vector<int> &growTime)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < plantTime.size(); i++)
        {
            v.push_back({plantTime[i], growTime[i]});
        }

        sort(v.begin(), v.end(), cmp);
        int st = 0;
        int res = 0;
        for (int i = 0; i < plantTime.size(); i++)
        {
            st += v[i].first;
            res = max(res, st + v[i].second);
        }

        return res;
    }
};
