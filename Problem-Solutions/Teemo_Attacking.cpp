#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        int count = 0;
        int n = timeSeries.size();
        for (int i = 1; i < n; i++)
        {
            if (timeSeries[i] - timeSeries[i - 1] >= duration)
                count += duration;
            else
                count += timeSeries[i] - timeSeries[i - 1];
        }
        count += duration;
        return count;
    }
};
