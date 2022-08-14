#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(int a, int b)
    {
        return a > b;
    }
    int maximumSwap(int num)
    {
        vector<int> v1;
        int n = num;
        while (n > 0)
        {
            v1.push_back(n % 10);
            n /= 10;
        }

        reverse(v1.begin(), v1.end());
        vector<int> v2 = v1;
        sort(v2.begin(), v2.end(), cmp);

        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] != v2[i])
            {
                int temp = v1[i];
                int k = i;
                int idx = 0;
                while (k < v1.size())
                {
                    if (v1[k] == v2[i])
                    {
                        idx = max(idx, k);
                    }
                    k++;
                }
                v1[i] = v2[i];
                v1[idx] = temp;
                break;
            }
        }

        int res = 0;
        for (int i = 0; i < v1.size(); i++)
        {
            res = res * 10 + v1[i];
        }
        return res;
    }
};