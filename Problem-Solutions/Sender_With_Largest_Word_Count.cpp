#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string largestWordCount(vector<string> &messages, vector<string> &senders)
    {
        unordered_map<string, int> m;
        int count = 0;
        for (int i = 0; i < messages.size(); i++)
        {
            count = 0;
            for (char c : messages[i])
            {
                if (c == ' ')
                    count++;
            }
            count++;

            m[senders[i]] += count;
        }

        string res = "";
        int len = 0;
        for (auto s : m)
        {
            if (s.second > len)
            {
                res = s.first;
                len = s.second;
            }
            else if (s.second == len and s.first > res)
            {
                res = s.first;
            }
        }

        return res;
    }
};
