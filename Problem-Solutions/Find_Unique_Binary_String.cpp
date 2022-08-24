#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string ans = "";
    void backtrack(int n, unordered_set<string> &s, string curr_str, int idx)
    {
        if (idx >= n)
        {
            if (s.find(curr_str) == s.end())
            {
                ans = curr_str;
            }
            return;
        }
        backtrack(n, s, curr_str + '0', idx + 1);
        if (ans != "") //means we have'nt got any answer that does not lie in the set
            return;
        backtrack(n, s, curr_str + '1', idx + 1);
        if (ans != "")
            return;
    }
    string findDifferentBinaryString(vector<string> &nums)
    {
        unordered_set<string> s(nums.begin(), nums.end());
        string curr_str = "";
        int n = nums[0].size();
        backtrack(n, s, curr_str, 0);
        return ans;
    }
};
