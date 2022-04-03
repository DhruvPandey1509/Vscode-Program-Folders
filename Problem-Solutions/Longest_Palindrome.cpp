#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        unordered_map<char, int> map;

        for (int i = 0; i < s.size(); i++)
        {
            map[s[i]]++;
        }

        int count = 0;
        bool flag = 0;

        for (auto it : map)
        {
            if (it.second % 2 == 0)
            {
                count += it.second;
            }
            else
            {
                count += it.second - 1;
                flag = 1;
            }
        }
        if (flag)
        {
            return count + 1;
        }
        return count;
    }
};