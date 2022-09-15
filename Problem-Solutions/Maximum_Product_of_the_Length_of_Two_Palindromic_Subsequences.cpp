#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int res = 0;
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    void dfs(string &s, int idx, string &s1, string &s2)
    {
        if (idx >= s.length())
        {
            if (isPalindrome(s1) && isPalindrome(s2))
            {
                int product = s1.length() * s2.length();
                res = max(res, product);
            }
            return;
        }
        // Case 1: Not Picking current character for subsequence
        dfs(s, idx + 1, s1, s2);

        // Case 2: Pick -> 2 cases
        // 2(a): Pick for 1st string
        s1.push_back(s[idx]);
        dfs(s, idx + 1, s1, s2);
        s1.pop_back();

        // 2(b): Pick for 2nd string
        s2.push_back(s[idx]);
        dfs(s, idx + 1, s1, s2);
        s2.pop_back();
    }

    int maxProduct(string s)
    {
        string s1 = "", s2 = "";
        dfs(s, 0, s1, s2);
        return res;
    }
};
