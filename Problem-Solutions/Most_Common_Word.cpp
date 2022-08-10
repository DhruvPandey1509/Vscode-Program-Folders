#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

        unordered_map<string, int> m;

        string str = "";
        for (int i = 0; i < paragraph.size(); i++)
        {
            if (isalpha(paragraph[i]))
            {
                str += paragraph[i];
            }
            else if (paragraph[i] == ' ' || paragraph[i] == ',')
            {
                if (str != "")
                {
                    m[str]++;
                    str = "";
                }
            }
        }

        m[str]++;
        str = "";

        for (int i = 0; i < banned.size(); i++)
        {
            m[banned[i]] = 0;
        }

        int n = INT_MIN;

        for (auto i : m)
        {
            if (i.second > n)
            {
                str = i.first;
                n = i.second;
            }
        }

        return str;
    }
};