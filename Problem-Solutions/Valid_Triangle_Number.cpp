#include "bits/stdc++.h"
using namespace std;

// Let three sides of the triangle be a, b, c;
// so it must satisfy the conditions
//  a + b > c
//  a + c > b
//  b + c > a
// if we choose c to be maximum then we need not check the last two conditions as
// it will hold true
// Now we only Need to check for condition 1 i.e a + b > c
// we will sort the array
//  make last(maximum) element as c , b previous to c and a starting of array
// then we will keep on checking for condition 1
// if the condition is true for current side values then we add the difference of the index of b and a to our result and move b one index back
// else we move a one index ahead
//  we will keep checking for all value of c till index 2 for c as a and b wil occupy the remaining first 2 position of index 0 and 1.
class Solution
{
public:
    int triangleNumber(vector<int> &nums)
    {

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0;

        for (int i = n - 1; i >= 2; i--)
        {
            int lo = 0;
            int hi = i - 1;

            while (lo < hi)
            {
                if (nums[lo] + nums[hi] > nums[i])
                {
                    res += (hi - lo);
                    hi--;
                }
                else
                {
                    lo++;
                }
            }
        }

        return res;
    }
};