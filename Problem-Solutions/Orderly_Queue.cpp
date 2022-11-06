#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k == 0)
        {
            return s;
        }
        else if(k > 1)
        {
            sort(s.begin(), s.end());
            return s;
        }
        else if(k==1)
        {
            string str = s;
            for (int i = 0; i < s.length()-1 ; i++)
            {
                string p = s.substr(i+1,s.length())+s.substr(0,i+1);
                if(str > p )
                {
                    str = p;
                }
            }
            return str;
        }
        return s;
    }
};