#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    static bool cmp(string a, string b)
    {
        // we cannot use greater<string>() because it will fail on testcase [3,30,34,5,9]
        // it wll give "9534303" insted of "9534330"
        string x = a + b;
        string y = b + a;

        return x > y;
    }
    string largestNumber(vector<int> &nums)
    {

        vector<string> v;

        for (int i = 0; i < nums.size(); i++)
        {
            v.push_back(to_string(nums[i]));
        }

        sort(v.begin(), v.end(), cmp);
        string res = "";

        for (int i = 0; i < v.size(); i++)
        {
            res += v[i];
        }

        for (int i = 0; i < res.size(); i++)
        {
            if (res[i] != '0')
                return res;
        }

        return "0";
    }
};