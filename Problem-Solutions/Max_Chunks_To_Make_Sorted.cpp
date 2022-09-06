#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int maxChunksToSorted(vector<int> &arr)
    {

        int max_val = 0;
        int count = 0;

        for (int i = 0; i < arr.size(); i++)
        {
            max_val = max(max_val, arr[i]);
            if (max_val == i)
                count++;
        }

        return count;
    }
};