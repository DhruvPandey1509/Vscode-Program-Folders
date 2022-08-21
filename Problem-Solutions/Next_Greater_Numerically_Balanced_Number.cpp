#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isBeautifulNumber(int n)
    {
        vector<int> nums(7, 0);
        while (n != 0)
        {
            int rightMost = n % 10;
            if (rightMost == 0 || rightMost > 6)
                return false;
            nums[rightMost]++;
            n /= 10;
        }
        for (int i = 1; i <= 6; i++)
        {
            if (nums[i] != 0 && nums[i] != i)
                return false;
        }
        return true;
    }
    int nextBeautifulNumber(int n)
    {
        while (true)
        {
            if (isBeautifulNumber(++n))
                return n;
        }
        return 0;
    }
};