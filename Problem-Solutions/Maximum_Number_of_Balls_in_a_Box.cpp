#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int sum(int num)
    {
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }
    int countBalls(int lowLimit, int highLimit)
    {
        unordered_map<int, int> m; // key = box, value = no. of balls

        for (int i = lowLimit; i <= highLimit; i++)
        {
            int n = sum(i);
            m[n]++;
        }

        int maxBall = INT_MIN;

        for (auto i : m)
        {
            maxBall = max(i.second, maxBall);
        }

        return maxBall;
    }
};