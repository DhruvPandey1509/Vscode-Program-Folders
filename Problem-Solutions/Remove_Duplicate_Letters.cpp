#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        map<char, int> freq;          // to store the frequency of the characters in string
        vector<bool> seen(26, false); // to keep track of already seen characters
        for (char c : s)
        {
            freq[c]++;
        }
        stack<char> st; // monotonic stack method

        for (char c : s)
        {
            // if character is already seen then decrease its frequency without including in stack
            if (seen[c - 'a'])
            {
                freq[c]--;
                continue;
            }
            // if the character in the stack top is greater in lexico order than the current character and it will appear again in string as we kept its count in map freq we will keep popping and changing their status seen as false
            while (!st.empty() and st.top() > c and freq[st.top()] > 0)
            {
                seen[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(c);
            seen[c - 'a'] = true;
            freq[c]--;
        }

        s = "";
        while (!st.empty())
        {
            s = st.top() + s;
            st.pop();
        }

        return s;
    }
};