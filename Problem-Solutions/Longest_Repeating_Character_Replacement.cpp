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
