#include "bits/stdc++.h"
using namespace std;

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

class Solution
{
public:
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i].profit, arr[i].dead});
        }

        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());

        int max_end_time = 0;
        for (int i = 0; i < n; i++)
        {
            max_end_time = max(max_end_time, v[i].second);
        }

        vector<int> fill(max_end_time, -1);
        int count = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
            int j = v[i].second - 1;

            while (j >= 0 and fill[j] != -1)
            {
                j--;
            }

            if (j >= 0 and fill[j] == -1)
            {
                fill[j] = i;
                count++;
                maxProfit += v[i].first;
            }
        }
        return {count, maxProfit};
    }
};