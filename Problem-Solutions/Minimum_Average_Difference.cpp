#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long int> left(n, 0);
        vector<long long int> right(n + 1, 0);
        left[0] = nums[0];
        right[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++)
        {
            left[i] = nums[i] + left[i - 1];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            right[i] = nums[i] + right[i + 1];
        }

        long long int avg = INT_MAX;
        int idx = -1;
        int count = 1;
        long long int average;
        for (int i = 0; i < n; i++)
        {
            if (n == count)
            {
                average = left[i] / n;
            }
            else
            {
                average = abs((left[i] / count) - right[i + 1] / (n - count));
            }

            if (average < avg)
            {
                avg = average;
                idx = i;
            }
            count++;
        }

        return idx;
    }
};

class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        int n = nums.size();
        long long int startSum = 0;
        long long int endSum = 0;

        for (auto i : nums)
            endSum += i;

        long long int avg = INT_MAX;
        long long int average = 0;
        int count = 1;
        int idx = -1;
        for (int i = 0; i < n; i++)
        {
            startSum += nums[i];
            endSum -= nums[i];
            if (count == n)
            {
                average = (startSum / n);
            }
            else
            {
                average = abs((startSum) / count - ((endSum) / (n - count)));
            }

            if (average < avg)
            {
                avg = average;
                idx = i;
            }
            count++;
        }

        return idx;
    }
};
