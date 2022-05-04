#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int findMidSum(int a1[], int a2[], int n)
    {
        vector<int> v;
        int i = 0, j = 0;

        while (i < n && j < n)
        {
            if (a1[i] < a2[j])
            {
                v.push_back(a1[i]);
                i++;
            }
            else
            {
                v.push_back(a2[j]);
                j++;
            }
        }

        while (i < n)
        {
            v.push_back(a1[i]);
            i++;
        }

        while (j < n)
        {
            v.push_back(a2[j]);
            j++;
        }

        int size = v.size();
        int i1 = (size / 2) - 1;
        int i2 = i1 + 1;

        return v[i1] + v[i2];
    }
};