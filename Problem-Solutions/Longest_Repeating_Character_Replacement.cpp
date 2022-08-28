#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int right = 0, left = 0, maxLetter = 0;
        vector<int> v(26, 0);
        while (right < s.length())
        {
            v[s[right] - 'A']++;
            maxLetter = max(maxLetter, v[s[right] - 'A']);
            right++;

            if (right - left - maxLetter > k)
            {
                v[s[left] - 'A']--;
                left++;
            }
        }
        return right - left;
    }
};
class Solution2
{
public:
    int characterReplacement(string s, int k)
    {
        int res = 0;
        unordered_map<int, int> m;
        int maxFreq = 0;
        int st = 0;
        int en = 0;
        while (en < s.size())
        {
            m[s[en]]++;
            maxFreq = max(maxFreq, m[s[en]]);

            int currLen = en - st + 1;

            if (currLen - maxFreq > k)
            {
                m[s[st]]--;
                st++;
            }

            currLen = en - st + 1; // in case st is increased
            res = max(res, currLen);
            en++;
        }

        return res;
    }
};