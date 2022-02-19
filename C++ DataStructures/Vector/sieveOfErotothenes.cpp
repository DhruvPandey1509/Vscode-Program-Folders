#include"bits/stdc++.h"
using namespace std;

void checkPrimeTill(int n)
{
    vector<int> v(n+1 , 0);
    for(int i = 2 ; i <= n ; i++)
    {
        if(v[i] == 0)
        {
            for(int j = pow(i,2); j <= 50 ; j += i)
            {
                v[j] = 1;
            }
        }
    }

    for(int i = 2 ; i <= n ; i++)
    {
       if(v[i] == 0)
       {
           cout<<i<<" ";
       }
    }
}

int main()
{
    checkPrimeTill(10);

    return 0;
}