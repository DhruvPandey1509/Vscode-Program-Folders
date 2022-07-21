#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity)
    {

        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int prev = 0, ans = 0, j = 0;
        for (int i = 0; i < buses.size(); i++)
        {
            int count = 0;
            while (j < passengers.size() && passengers[j] <= buses[i] && count < capacity)
            {
                if (passengers[j] - prev > 1)
                    ans = passengers[j] - 1;
                prev = passengers[j];
                j++;
                count++;
            }

            if (count < capacity and buses[i] - prev >= 1)
                ans = buses[i];
        }

        return ans;
    }
};