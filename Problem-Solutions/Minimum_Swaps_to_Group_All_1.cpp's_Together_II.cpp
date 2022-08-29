#include "bits/stdc++.h"
using namespace std;

// Idea:
// We want to find the "window" of size ones with the most ones.
// First, we count the ones in the original array.
// Now, because the array is circular, the easiest way is to concatenate two arrays and then we can search the window regularly.
// We count the ones in the initial window in the left - from index 0 to ones.
// Then, in each iteration, we move the window one step to the right.
// If the number we removed in the left is a one - we decrement ones_in_window.
// If the number we added in the right is a one - we increment ones_in_window.
// We keep track of the mx.
// Our result will be ones - mx because we need the number of zeros to swap in the window.

// Time Complexity: O(n)
// Space Complexity: O(n) (Because we are doubling the array)

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {

        int ones = count(nums.begin(), nums.end(), 1);
        nums.insert(nums.end(), nums.begin(), nums.end());

        int ones_in_window = 0;
        for (int i = 0; i < ones; i++)
        {
            ones_in_window += nums[i];
        }

        int total_ones_together = ones_in_window;

        for (int i = ones; i < nums.size(); i++)
        {
            if (nums[i - ones] == 1)
                ones_in_window--;
            if (nums[i] == 1)
                ones_in_window++;
            total_ones_together = max(total_ones_together, ones_in_window);
        }

        return ones - total_ones_together;
    }
};
