#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {

        int max_reach = startFuel; // max dis we can reach with the fuel in our tank
        priority_queue<int> pq;    // to store the fuel that can be refilled in the car from the stations within the vicinity of our reach while traveling

        int count = 0;
        int idx = 0;
        while (max_reach < target)
        {
            // storing fuel provided by gas stations in our priority queue
            while (idx < stations.size() and stations[idx][0] <= max_reach)
            {
                pq.push(stations[idx][1]); // fuel
                idx++;
            }

            if (pq.empty())
                return -1; // since or max_reach is yet not >= to target and pq is empty it means we cannot react our target

            max_reach += pq.top();
            pq.pop();
            count++;
        }

        return count;
    }
};