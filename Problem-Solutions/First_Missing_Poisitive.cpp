#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &arr)
    {
        int k = arr.size();
        if (arr.size() == 0)
        {
            return 0;
        }
        for (int i = 0; i < k; i++)
        {
            while (arr[i] > 0 && arr[i] < k && arr[arr[i] - 1] != arr[i])
            {
                swap(arr[i], arr[arr[i] - 1]);
            }
        }
        for (int i = 0; i < k; i++)
        {
            if (arr[i] != i + 1)
            {
                return i + 1;
            }
        }
        return k + 1;
    }
};