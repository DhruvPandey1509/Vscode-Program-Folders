#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> m;
        int l = 0;
        for (int i = 0; i < key.size(); i++)
        {
            if (m.find(key[i]) != m.end())
                continue;
            if (key[i] != ' ')
            {
                m[key[i]] = 'a' + l;
                l++;
            }
        }
        string res = "";
        for (int i = 0; i < message.size(); i++)
        {
            if (message[i] == ' ')
                res += " ";
            else
            {
                res += m[message[i]];
            }
        }

        return res;
    }
};