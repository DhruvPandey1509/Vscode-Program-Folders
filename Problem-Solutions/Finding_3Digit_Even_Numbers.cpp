#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<int> findEvenNumbers(vector<int> &digits)
    {
        vector<int> v(10, 0);
        bool flag = true;
        for (auto i : digits)
        {
            v[i]++;
        }
        vector<int> res;
        for (int num = 100; num < 999; num += 2)
        {
            vector<int> count(10, 0);
            int temp = num;

            while (temp)
            {
                count[temp % 10]++;
                temp /= 10;
            }

            flag = true;
            for (int i = 0; i < 10; i++)
            {
                if (count[i] > v[i])
                {
                    flag = false;
                    break;
                }
            }

            if (flag)
            {
                res.push_back(num);
            }
        }

        return res;
    }
};
