#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int maxSatisfied = 0;
        int n = customers.size();
        int size = 0;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 0)
                maxSatisfied += customers[i];
        }
        int satisfied = maxSatisfied;
        for (int i = 0; i < n; i++)
        {
            if (grumpy[i] == 1)
            {
                satisfied += customers[i];
            }
            size++;
            if (size > minutes)
            {
                if (grumpy[i - minutes] == 1)
                {
                    satisfied -= customers[i - minutes];
                }
                size--;
            }
            maxSatisfied = max(maxSatisfied, satisfied);
        }

        return maxSatisfied;
    }
};