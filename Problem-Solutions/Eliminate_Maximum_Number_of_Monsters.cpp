#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        vector<int> reach;
        for (int i = 0; i < dist.size(); i++)
        {
            reach.push_back(ceil(dist[i] * 1.0 / speed[i]));
        }

        int curr_min = 0;
        sort(reach.begin(), reach.end());
        int res = 0;
        for (int i = 0; i < reach.size(); i++)
        {
            if (i >= reach[i])
                break;
            res++;
        }

        return res;
    }
};