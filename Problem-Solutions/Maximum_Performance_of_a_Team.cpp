#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    const int mod = (int)1e9 + 7;
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
    int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < speed.size(); i++)
        {
            v.push_back({efficiency[i], speed[i]});
        }
        sort(v.begin(), v.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;

        long total_speed = 0, res = 0;

        for (int i = 0; i < n; i++)
        {
            int currEff = v[i].first;
            int currSpeed = v[i].second;

            if (pq.size() == k)
            {
                total_speed -= pq.top();
                pq.pop();
            }

            pq.push(currSpeed);
            total_speed += currSpeed;
            res = max(res, total_speed * currEff);
        }

        return res % mod;

        return 60;
    }
};
