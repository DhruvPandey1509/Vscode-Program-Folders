#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    // arr[] : the input array
    // N : size of the array arr[]

    // Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int n)
    {
        int count = 0;
        int prev = -1;
        int res = 0;

        map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[a[i]] = 1;
        }

        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->first == prev)
            {
                count++;
            }
            else
            {
                count = 1;
            }

            res = max(res, count);
            prev = it->first + 1;
        }

        return res;
    }
};