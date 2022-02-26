#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() <= 1)
        {
          return s.size();
        }
        
        int start = -1, end = 0, maxlen = 0;
        vector<int> dict(256,-1);
        
        for(int end = 0 ; end < s.size(); end++)
        {
           if(dict[s[end]] > start)
           {
              start = dict[s[end]];
           }
            dict[s[end]] = end;
            maxlen = max(maxlen, end-start);
        }
        
        return maxlen;
        
    }
};