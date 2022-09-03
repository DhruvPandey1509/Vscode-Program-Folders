#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &candies, long long k, long long mid)
    {
        long long split = 0;
        for (int i = 0; i < candies.size(); ++i)
        {
            split += candies[i] / mid;
        }
        if (split >= k)
            return true;
        else
            return false;
    }

    int maximumCandies(vector<int> &candies, long long k)
    {
        long long total_candies = 0;
        for (auto i : candies)
        {
            total_candies += i;
        }
        // start denotes the min of candies that we are splitting
        // end denotes the maximum that can be allocated hypothetically
        long long start = 1, end = total_candies / k;
        long long res = 0;

        // applying binary search to search for the number of the max number of candies that can be distributed among k children
        while (start <= end)
        {
            long long mid = (start + end) / 2; // mid denotes the number of candies that we are trying to distribute
            if (canSplit(candies, k, mid))     // can split function checks whether all the candies individually can be split into candies with mid number of candies in one of its split piles
            {
                res = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return res;
    }
};
