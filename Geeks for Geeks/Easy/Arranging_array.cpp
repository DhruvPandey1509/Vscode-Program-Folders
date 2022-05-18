#include "bits/stdc++.h"
using namespace std;

void Rearrange(int a[], int n)
{
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
        {
            v.push_back(a[i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            v.push_back(a[i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        a[i] = v[i];
    }
}