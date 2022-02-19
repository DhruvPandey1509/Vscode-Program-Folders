#include"bits/stdc++.h"
using namespace std;

int main()
{
    int a[] = {3,-1,-1,10,-4,2};
    int n = sizeof(a)/sizeof(a[0]);
    int currSum = 0; 
    int maxSum = INT16_MIN;

    for(int i = 0 ; i < n ; i++)
    {
        currSum += a[i];
        if(currSum < 0)
        {
            currSum = 0;
        }

        maxSum = max(maxSum, currSum);
    }

    cout<<maxSum<<endl;

    return 0;
}

//Order of this Algorithm is O(n);