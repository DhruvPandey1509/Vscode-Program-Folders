/*
For a given array and integers a and X, find the maximum sum subarray of size a and having sum
less than X.
*/

#include <iostream>
using namespace std;

int minSum(int *a, int n, int x)
{
    int sum = 0 , minLength = n+1 , start = 0, end = 0;
    while(end < n)
    {
        while(sum <= x && end < n)
        {
            sum += a[end++];
        }
        while(sum > x && start < n)
        {
            if(end-start < minLength)
            {
                minLength = end - start;
            }

            sum -= a[start++];
        }
    }

    return minLength;
}

int main()
{
    int a[] = {1,4,45,6,10,19};
    int x = 51;
    int n = 6;
    int minLength = minSum(a,n,x);
    (minLength == n+1) ? cout<<"No such Subarray Exist"<<endl:cout<<"Smallest subarray is : "<<minLength<<endl;

    return 0;
}