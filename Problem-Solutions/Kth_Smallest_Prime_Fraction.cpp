#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
    {
        priority_queue<pair<float, pair<int, int>>, vector<pair<float, pair<int, int>>>, greater<pair<float, pair<int, int>>>> pq;
        int n = arr.size();

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                float res = arr[i] / (arr[j] * 1.0);
                pq.push({res, {arr[i], arr[j]}});
            }
        }

        k -= 1;

        while (!pq.empty() and k--)
        {
            pq.pop();
        }

        return {pq.top().second.first, pq.top().second.second};
    }
};
