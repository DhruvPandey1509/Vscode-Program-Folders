#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        string res = strs[0]; // Asuming that first string is the longest common string

        for (string s : strs) // iterating over the strs
        {
            for (int i = 0; i < res.size(); i++)
            {
                if (s[i] != res[i])
                {
                    res = res.substr(0, i); // if we get any char not equal to the longest string result then we will update our result string upto the lonest common substring
                }
            }
        }

        return res;
    }
};