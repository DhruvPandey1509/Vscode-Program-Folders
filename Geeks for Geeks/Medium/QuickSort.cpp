#include "bits/stdc++.h"
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quickSort(int a[], int lo, int hi)
{
    if (lo < hi)
    {
        int p = partition(a, lo, hi);
        quickSort(a, lo, p - 1);
        quickSort(a, p + 1, hi);
    }
}
int partition(int a[], int lo, int hi)
{
    int pivot = a[hi];
    int i = lo - 1;

    for (int j = lo; j < hi; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[hi]);
    return i + 1;
}