#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int numFactoredBinaryTrees(vector<int> &arr)
    {

        map<int, long long int> m;

        sort(arr.begin(), arr.end());

        for (auto i : arr)
        {
            m[i] = 1;
        }

        for (int i = 1; i < arr.size(); i++)
        {
            long long int count = 0;
            for (int j = 0; j < i; j++)
            {
                if (arr[i] % arr[j] == 0)
                {
                    auto it1 = m.find(arr[i] / arr[j]);
                    auto it2 = m.find(arr[j]);

                    if (it1 != m.end())
                    {
                        count += (it1->second) * (it2->second);
                    }
                }
            }

            m[arr[i]] += count;
        }
        long long int sum = 0;
        for (auto i : m)
        {
            sum += i.second;
        }

        return sum % (1000000007);
    }
};