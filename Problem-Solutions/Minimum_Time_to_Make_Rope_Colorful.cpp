#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int time = 0;
        int n = colors.size();
        int prev = 0;
        for (int i = 1; i < n; i++)
        {
            if (colors[i] == colors[i - 1])
            {
                if (neededTime[i] < neededTime[prev])
                {
                    time += neededTime[i];
                }
                else
                {
                    time += neededTime[prev];
                    prev = i;
                }
            }
            else
                prev = i;
        }

        return time;
    }
};