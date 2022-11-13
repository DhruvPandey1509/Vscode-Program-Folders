#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        unordered_map<char, int> m;
        int len = 0;
        int max_len = 0;
        for (int i = 0; i < word.size(); i++)
        {
            if (i == 0)
            {
                m[word[i]]++;
                len = 1;
                continue;
            }
            if (word[i] >= word[i - 1])
            {
                m[word[i]]++;
                len++;
                continue;
            }
            else
            {
                if (m['a'] != 0 && m['e'] != 0 && m['i'] != 0 && m['o'] != 0 && m['u'] != 0)
                {
                    max_len = max(max_len, len);
                }

                len = 1;
                m.clear();
                m[word[i]] = 1;
            }
        }

        // aeiou
        if (m['a'] != 0 && m['e'] != 0 && m['i'] != 0 && m['o'] != 0 && m['u'] != 0)
        {
            max_len = max(max_len, len);
        }
        return max_len;
    }
};
