#include "bits/stdc++.h"
using namespace std;
class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int left = 0, right = 0, end = s.size() - 1;
        unordered_map<char, int> m;

        int count = 0;

        while (right != s.size())
        {
            m[s[right]]++;
            while (m['a'] and m['b'] and m['c'])
            {
                // including the current string and all the other strings starting from right till the end
                count += 1 + (end - right);

                m[s[left]]--;
                left++;
            }

            right++;
        }

        return count;
    }
};