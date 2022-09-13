#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> pancakeSort(vector<int> &arr)
    {
        int n = arr.size();

        int curr = n, i = 0;
        vector<int> v;
        while (curr > 0)
        {
            int pos = -1;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == curr)
                {
                    pos = i;
                    break;
                }
            }

            if (pos == curr - 1)
                curr--;
            else
            {
                v.push_back(pos + 1);
                reverse(arr.begin(), arr.begin() + pos + 1);
                v.push_back(curr);
                reverse(arr.begin(), arr.begin() + curr);
                curr--;
            }
        }
        for (auto i : arr)
            cout << i << " ";
        return v;
    }
};