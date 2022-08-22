#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks)
    {
        vector<int> v;

        for (int i = 0; i < capacity.size(); i++)
        {
            v.push_back(capacity[i] - rocks[i]);
        }

        sort(v.begin(), v.end());
        int count = 0;
        for (int i = 0; i < v.size() and additionalRocks > 0; i++)
        {
            if (v[i] == 0)
                continue;
            if (v[i] <= additionalRocks)
            {
                additionalRocks -= v[i];
                v[i] = 0;
            }
            else
                break;
        }

        for (auto i : v)
        {
            if (i == 0)
            {
                count++;
            }
        }

        return count;
    }
};