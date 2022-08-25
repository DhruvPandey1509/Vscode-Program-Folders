#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        
        int n = a+b+c;
        int A = 0, B = 0, C = 0;
        string res = "";
        for(int i = 0 ; i < n; i++)
        {
            if((a >= b and a >= c and A != 2) || (B == 2 and a > 0) || (C == 2 and a > 0))
            {
                res += "a";
                A++, a--, B = 0, C = 0;
            }
            else if((b >= a and b >= c and B!= 2) || (A == 2 and b > 0) || (C == 2 and b > 0))
            {
                res += "b";
                B++, b--, A=0, C=0;
            }
            else if((c >= a and c >= b and C!= 2) || (A == 2 and c > 0) || (B == 2 and c > 0))
            {
                res += "c";
                C++, c--, A=0, B=0;
            }
        }
        
        return res;
    }
};