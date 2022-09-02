#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<vector<int>> v;

        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++)
        {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }

        while (!pq.empty() and k--)
        {
            int x = pq.top().second.first, y = pq.top().second.second;
            pq.pop();
            v.push_back({nums1[x], nums2[y]});
            if (y != m - 1)
            {
                pq.push({nums1[x] + nums2[y + 1], {x, y + 1}});
            }
        }
        return v;
    }
};
