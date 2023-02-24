#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> p;
        int minVal = INT_MAX;

        for (int num : nums)
        {
            if (num % 2 == 1)
            {
                num = num * 2;
            }
            p.push(num);
            minVal = min(minVal, num);
        }

        int minDeviation = INT_MAX;
        while (1)
        {
            int maxVal = p.top();
            p.pop();

            minDeviation = min(minDeviation, maxVal - minVal);
            if (maxVal % 2 == 1)
                break;
            maxVal = maxVal / 2;
            minVal = min(minVal, maxVal);
            p.push(maxVal);
        }
        return minDeviation;
    }
};
