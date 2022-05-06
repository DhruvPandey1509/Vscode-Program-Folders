#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
public:
    int kthElement(int a1[], int a2[], int n, int m, int k)
    {
        int i = 0, j = 0;
        int count = 0;
        while (i < n && j < m)
        {
            if (a1[i] < a2[j])
            {
                i++;
                count++;
                if (count == k)
                {
                    return a1[i - 1];
                }
            }
            else
            {
                j++;
                count++;
                if (count == k)
                {
                    return a2[j - 1];
                }
            }
        }

        if (i == n)
        {
            return a2[j + k - count - 1];
        }
        else
        {
            return a1[i + k - count - 1];
        }
    }
};