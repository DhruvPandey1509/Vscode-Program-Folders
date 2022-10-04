#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> numMovesStones(int a, int b, int c)
    {
        vector<int> nums = {a, b, c};
        sort(nums.begin(), nums.end());

        if (nums[2] - nums[0] == 2)
        {
            return {0, 0};
        }

        int leftGap = nums[1] - nums[0] - 1;
        int rightGap = nums[2] - nums[1] - 1;
        int maxMoves = leftGap + rightGap;
        int minMoves = 0;
        if (leftGap < 2 || rightGap < 2)
        {
            minMoves = 1;
        }
        else
        {
            minMoves = 2;
        }

        return {minMoves, maxMoves};
    }
};
