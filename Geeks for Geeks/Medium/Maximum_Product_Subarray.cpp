#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int> arr, int n)
    {
        long long left = 1, right = 1;
        long long leftMax = INT_MIN, rightMax = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            left *= arr[i];
            right *= arr[(n - 1) - i];

            leftMax = max(leftMax, left);
            rightMax = max(rightMax, right);

            if (arr[i] == 0)
            {
                left = 1;
            }

            if (arr[(n - 1) - i] == 0)
            {
                right = 1;
            }
        }

        return max(leftMax, rightMax);
    }
};