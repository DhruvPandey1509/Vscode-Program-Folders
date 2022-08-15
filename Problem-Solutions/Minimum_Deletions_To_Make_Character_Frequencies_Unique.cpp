#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    int minDeletions(string s)
    {
        vector<int> freq(26, 0);

        for (int i = 0; i < s.size(); i++)
        {
            freq[s[i] - 'a']++;
        }

        int count = 0;
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i] != 0)
            {
                for (int j = 0; j < freq.size(); j++)
                {
                    if (i != j and freq[i] == freq[j])
                    {
                        freq[i]--;
                        count++;
                        i--;
                        break;
                    }
                }
            }
        }

        return count;
    }
};