#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    vector<string> v = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    int uniqueMorseRepresentations(vector<string> &words)
    {
        unordered_set<string> st;

        for (auto word : words)
        {
            string str = "";
            for (char c : word)
            {
                str += v[c - 'a'];
            }
            st.insert(str);
        }

        return st.size();
    }
};