#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int operations = target[0];
        int n = target.size();
        for (int i = 1; i < n; i++)
        {
            if (target[i] > target[i - 1])
            {
                operations += target[i] - target[i - 1];
            }
        }

        return operations;
    }
};