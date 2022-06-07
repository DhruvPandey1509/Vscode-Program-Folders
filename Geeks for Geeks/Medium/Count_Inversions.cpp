#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long int mergeSort(long long a[], long long l, long long mid, long long r)
    {
        long long n1 = mid - l + 1;
        long long n2 = r - mid;

        long long int inv_count = 0;

        long long left[n1];
        long long right[n2];

        for (long long i = 0; i < n1; i++)
        {
            left[i] = a[l + i];
        }
        for (long long i = 0; i < n2; i++)
        {
            right[i] = a[mid + i + 1];
        }

        long long i = 0, j = 0, k = l;

        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                a[k++] = left[i++];
            }
            else
            {
                a[k++] = right[j++];
                inv_count += n1 - i;
            }
        }

        while (i < n1)
        {
            a[k++] = left[i++];
        }

        while (j < n2)
        {
            a[k++] = right[j++];
        }

        return inv_count;
    }

    long long int merge(long long a[], long long l, long long r)
    {
        long long int inv_count = 0;
        if (r > l)
        {
            long long mid = l + (r - l) / 2;

            inv_count += merge(a, l, mid);
            inv_count += merge(a, mid + 1, r);
            inv_count += mergeSort(a, l, mid, r);
        }

        return inv_count;
    }

    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long a[], long long n)
    {
        long long int inv = merge(a, 0, n - 1);
        return inv;
    }
};