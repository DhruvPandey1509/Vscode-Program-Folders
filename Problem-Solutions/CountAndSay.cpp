#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        
       if(n == 1) return "1";
       
       if(n == 2) return "11";
    
       string s = "11";
       
       for(int i = 3; i <= n; i++)
       {
           string curr = "";//to store current string
           int count = 1;  //to count number of same value
           for(int j = 0; j < s.length(); j++)
           {
               if(s[j] != s[j+1])
               {
                   curr += to_string(count) + s[j];
                   count = 1;
               }
               else
               {
                   count++;
               }
           }
           
           s = curr;
       }
        
        return s;
        
    }
};