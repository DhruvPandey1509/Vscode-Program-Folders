#include "bits/stdc++.h"
using namespace std;

//T.C = 0(n)    S.C = O(n)  
class Solution1 {
  public:
    void reArrange(int a[], int n) {
        vector<int> odd;
        vector<int> even;

        for(int i = 0 ; i < n; i++)
        {
            if(a[i]%2 == 0)
            {
                even.push_back(a[i]);
            }
            else
            {
                odd.push_back(a[i]);
            }
        }
        
        int j = 0;
        for(int i = 0 ; i < even.size(); i++)
        {
            a[j] = even[i];
            j += 2;
        }
        
        j = 1;
        for(int i = 0 ; i < odd.size(); i++)
        {
            a[j] = odd[i];
            j += 2;
        }
    }
};

// T.C = O(n)  S.C = O(1)
class Solution
{
public:
    void reArrange(int a[], int n)
    {
        int i = 0, j = 1;
        while (i < n && j < n)
        {
            if (a[i] % 2 != 0)
            {
                if (a[j] % 2 == 0)
                {
                    swap(a[i], a[j]);
                }
                else
                {
                    j += 2;
                }
            }
            else
            {
                i += 2;
            }
        }
    }
};