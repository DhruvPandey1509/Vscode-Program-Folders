#include "bits/stdc++.h"
using namespace std;

void heapify(vector<int> &v, int n, int i)
{
    int maximum = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n and v[l] > v[maximum])
        l = maximum;
    if (r < n and v[r] > v[maximum])
        r = maximum;

    if (i != maximum)
    {
        swap(v[i], v[maximum]);
    }

    heapify(v, n, maximum);
}

void heapSort(vector<int> &v, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(v, n, i);
    }

    for (int i = n - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}

int main()
{
    // int n;
    // cin >> n;
    vector<int> v = {12, 11, 13, 5, 6, 7};
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
    int n = v.size();
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    heapSort(v, n);

    for (auto i : v)
    {
        cout << i << " ";
    }
    return 0;
}