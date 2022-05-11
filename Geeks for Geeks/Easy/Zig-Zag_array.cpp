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
    // Program for zig-zag conversion of array
    void zigZag(int a[], int n)
    {
        bool flag = true;

        for (int i = 0; i < n - 1; i++)
        {
            if (flag)
            {
                if (a[i] > a[i + 1])
                {
                    swap(&a[i], &a[i + 1]);
                }
            }
            else
            {
                if (a[i] < a[i + 1])
                {
                    swap(&a[i], &a[i + 1]);
                }
            }

            flag = !flag;
        }
    }
};