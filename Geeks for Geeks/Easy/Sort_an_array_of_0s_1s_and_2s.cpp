#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    void swap(int *x, int *y)
    {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
    void sort012(int a[], int n)
    {
        int lo = 0;
        int hi = n - 1;
        int mid = 0;

        while (mid <= hi)
        {
            if (a[mid] == 0)
            {
                swap(&a[mid], &a[lo]);
                lo++;
                mid++;
            }
            else if (a[mid] == 1)
            {
                mid++;
            }
            else
            {
                swap(&a[mid], &a[hi]);
                hi--;
            }
        }
    }
};