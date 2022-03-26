#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }
        int maxP = 0;  // maximum Product
        int currP = 1; // current Product
        for (int i = 0; i < nums.size(); i++)
        {

            currP *= nums[i];
            maxP = max(maxP, currP);
            if (currP == 0)
            {
                currP = 1;
            }
        }
        currP = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {

            currP *= nums[i];
            maxP = max(maxP, currP);
            if (currP == 0)
            {
                currP = 1;
            }
        }
        return maxP;
    }
};