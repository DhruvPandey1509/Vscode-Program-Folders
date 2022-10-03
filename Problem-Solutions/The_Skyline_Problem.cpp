#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
    {
        priority_queue<pair<int, int>> pq;
        vector<int> v;
        int n = buildings.size();
        for (auto b : buildings)
        {
            v.push_back(b[0]);
            v.push_back(b[1]);
        }
        sort(v.begin(), v.end());
        int m = unique(v.begin(), v.end()) - v.begin();

        int j = 0, prevHt = 0;

        vector<vector<int>> res;

        for (int i = 0; i < m; i++)
        {

            while (j < n and buildings[j][0] <= v[i])
            {
                pq.push({buildings[j][2], buildings[j][1]});
                j++;
            }

            while (!pq.empty() and pq.top().second <= v[i])
            {
                pq.pop();
            }

            int newH = pq.empty() ? 0 : pq.top().first;

            if (newH != prevHt)
            {
                res.push_back({v[i], newH});
                prevHt = newH;
            }
        }
        return res;
    }
};