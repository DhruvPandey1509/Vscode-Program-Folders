#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int minK, int maxK)
    {
        long long res = 0;
        int j1 = -1, j2 = -1, k = -1;
        // j1 maintains the index of the minK element in array
        // j2 maintains the index of the maxK element in array
        // k is the index of the element that is either smaller than minK
        // or greater than maxK because it splits the array.
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] > maxK || nums[i] < minK)
                k = i;
            if (nums[i] == minK)
                j1 = i;
            if (nums[i] == maxK)
                j2 = i;
            res += max(0, min(j1, j2) - k); // we subtracting k to get the starting address from where we can count the starting of the new index of the splitted index.
        }
        return res;
    }
};
