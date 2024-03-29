#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        vector<int> pos;
        vector<int> neg;

        for (auto i : nums)
        {
            if (i >= 0)
                pos.push_back(i);

            else
                neg.push_back(i);
        }

        int i = 0, j = 0, k = 0;
        bool flag = true;

        while (i < pos.size() || j < neg.size())
        {
            if (flag)
            {
                nums[k++] = pos[i++];
            }
            else
            {
                nums[k++] = neg[j++];
            }
            flag = !flag;
        }

        return nums;
    }
};