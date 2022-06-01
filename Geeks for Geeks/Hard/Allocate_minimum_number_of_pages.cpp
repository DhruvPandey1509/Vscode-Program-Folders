#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    bool isFeasible(int a[], int n, int k, int mid)
    {
        int sum = 0;
        int students = 1;

        for (int i = 0; i < n; i++)
        {
            if (sum + a[i] > mid)
            {
                students++;
                sum = a[i];
                if (students > k)
                    return false;
            }
            else
            {
                sum += a[i];
            }
        }

        return students <= k;
    }

    // Function to find minimum number of pages.
    int findPages(int a[], int n, int k) // k = no. of students
    {
        // min_num = gives the minimum point for the range
        // max_num = gives the maximum point for the range

        int min_num = INT_MIN;
        int max_num = 0;
        for (int i = 0; i < n; i++)
        {
            max_num += a[i];
            min_num = max(min_num, a[i]);
        }
        int res = 0;
        while (min_num <= max_num)
        {
            int mid = min_num + (max_num - min_num) / 2;

            if (isFeasible(a, n, k, mid))
            {
                res = mid;
                max_num = mid - 1;
            }
            else
            {
                min_num = mid + 1;
            }
        }

        return res;
    }
};