#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(pair<char, int> a, pair<char, int> b)
    {
        if (a.second == b.second)
        {
            return a.first > b.first;
        }
        return a.second > b.second;
    }

    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        vector<pair<char, int>> v;
        v.push_back({keysPressed[0], releaseTimes[0]});
        for (int i = 1; i < releaseTimes.size(); i++)
        {
            v.push_back({keysPressed[i], releaseTimes[i] - releaseTimes[i - 1]});
        }

        sort(v.begin(), v.end(), cmp);

        return v[0].first;
    }
};