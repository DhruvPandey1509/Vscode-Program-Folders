#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> removeAnagrams(vector<string> &words)
    {
        int idx1 = 0;
        int idx2 = idx1 + 1;

        string str1 = words[idx1];
        sort(str1.begin(), str1.end());

        vector<string> res;
        string str2;

        while (idx2 < words.size())
        {
            str2 = words[idx2];
            sort(str2.begin(), str2.end());

            if (str1 == str2) // anagram
            {
                idx2++;
            }
            else if (str1 != str2)
            {
                res.push_back(words[idx1]);
                idx1 = idx2;
                str1 = words[idx1];
                sort(str1.begin(), str1.end());
                idx2 = idx1 + 1;
            }
        }
        res.push_back(words[idx1]);
        return res;
    }
};