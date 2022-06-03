#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to find the maximum number of activities that can
    // be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        int count = 0;
        int currend = -1;
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({end[i], start[i]});
        }

        sort(v.begin(), v.end());

        for (int i = 0; i < v.size(); i++)
        {
            if (v[i].second > currend)
            {
                count++;
                currend = v[i].first;
            }
        }

        return count;
    }
};