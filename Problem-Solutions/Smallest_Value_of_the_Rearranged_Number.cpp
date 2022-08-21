#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    long long smallestNumber(long long num)
    {
        if (num == 0)
            return 0;

        bool isNegative = false;
        if (num < 0)
        {
            isNegative = true;
            num *= -1;
        }
        string s = to_string(num);

        map<int, int> m;
        bool isZero = false;

        for (char i : s)
        {
            if (i == '0')
                isZero = true;

            m[i - '0']++;
        }
        string res = "";

        if (isNegative)
        {
            for (int i = 9; i >= 0; i--)
            {
                if (m.find(i) != m.end())
                {
                    int x = m[i];
                    while (x--)
                    {
                        res += i + '0';
                    }
                }
            }
        }
        else
        {
            int zeroCount = 0;
            for (auto i : m)
            {
                if (i.first == 0)
                {
                    zeroCount = i.second;
                    continue;
                }
                else
                {
                    int x = i.second - 1;
                    res += to_string(i.first);
                    if (isZero)
                    {
                        while (zeroCount--)
                        {
                            res += '0';
                        }
                        isZero = false;
                    }

                    while (x--)
                    {
                        res += to_string(i.first);
                    }
                }

                if (isZero)
                {
                    while (zeroCount--)
                    {
                        res += '0';
                    }
                    isZero = false;
                }
            }
        }
        num = stoll(res);

        if (isNegative)
            num *= -1;

        return num;
    }
};