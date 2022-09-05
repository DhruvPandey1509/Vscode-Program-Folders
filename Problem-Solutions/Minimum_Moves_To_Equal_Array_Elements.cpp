#include "bits/stdc++.h"
using namespace std;

// Approach
//  1.) we will choose the smallest element out of the whole array
//  2.) Now we will find out how many operations are required to turn the other array elements to the smallest value
//  for instance in the array [1,2,3] 1 is smallest, so to convert rest to 1 we require
//  (1-1 = 0 steps) + (2 - 1 =  1steps) + (3-1 = 2 steps) .: 3 steps in total
// generalizing the formula =  [  sum of the array - (size of the array) * (minimum element) ]

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0);    // sum of the whole array
        int min_num = *min_element(nums.begin(), nums.end()); // finding the minimum element in the array
        int n = nums.size();
        return (sum - n * min_num);
    }
};

class Solution1
{
public:
    int minMoves(vector<int> &nums)
    {

        int sum = 0;
        int mini = INT_MAX;
        int n = nums.size();
        for (auto i : nums)
        {
            sum += i;
            mini = min(mini, i);
        }

        return sum - mini * n;
    }
};