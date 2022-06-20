#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        int curr = 0;
        int jumps = 0;
        int maxi = 0;

        for (int i = 0; i < n - 1; i++)
        {
            maxi = max(maxi, arr[i] + i);
            if (i == curr)
            {
                curr = maxi;
                jumps++;
            }
        }

        if (curr < n - 1)
        {
            return -1;
        }

        return jumps;
    }
};