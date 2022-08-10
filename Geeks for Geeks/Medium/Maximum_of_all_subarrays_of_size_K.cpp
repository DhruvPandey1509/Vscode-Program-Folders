#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> res;
        priority_queue<pair<int, int>> p;

        for (int i = 0; i < k; i++)
        {
            p.push({arr[i], i});
        }

        res.push_back(p.top().first);

        for (int i = k; i < n; i++)
        {
            p.push({arr[i], i});
            while (!p.empty() and (p.top().second <= (i - k)))
            {
                p.pop();
            }
            res.push_back(p.top().first);
        }

        return res;
    }
};