#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {

        int maxDist = 0;

        for (int i = 0; i < nums1.size(); i++)
        {
            int l = i;
            int r = nums2.size() - 1;
            int index = -1;

            while (l <= r)
            {
                int mid = l + (r - l) / 2;
                if (nums2[mid] < nums1[i])
                    r = mid - 1;
                else
                {
                    index = mid;
                    l = mid + 1;
                }
            }

            if (index != -1)
                maxDist = max(maxDist, (index - i));
        }
        return maxDist;
    }
};