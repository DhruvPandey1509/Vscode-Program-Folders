#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x)
    {
        priority_queue<pair<int, int>> p;

        for (int i = 0; i < arr.size(); i++)
        {
            int diff = abs(arr[i] - x);
            p.push({diff, arr[i]});
            if (p.size() > k)
                p.pop();
        }

        vector<int> v;
        while (!p.empty())
        {
            v.push_back(p.top().second);
            p.pop();
        }
        sort(v.begin(), v.end());

        return v;
    }
};