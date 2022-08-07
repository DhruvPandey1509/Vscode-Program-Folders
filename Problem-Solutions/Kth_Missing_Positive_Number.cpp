#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findKthPositive(vector<int> &arr, int k)
    {
        unordered_map<int, int> m;
        for (int i = 0; i < arr.size(); i++)
        {
            m[arr[i]]++;
        }

        int count = 0;
        int i = 1;
        while (count < k)
        {
            if (m.find(i) == m.end())
            {
                count++;
            }
            if (count == k)
                break;

            i++;
        }

        return i;
    }
};