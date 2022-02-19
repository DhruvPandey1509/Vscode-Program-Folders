#include<iostream>
#include<vector>
using namespace std;

// top down dp
int fib(int n, int dp[])
{
    if(n == 0 || n == 1)
    {
        return n;
    }
    if(dp[n] != 0)
    {
        return dp[n];
    }

    return dp[n] = fib(n-1,dp) + fib(n-2,dp);
}

//bottom up dp
int fib2(int n)
{
    int dp[n+1] = {0};
    dp[0] = 0;
    dp[1] = 1;

    for(int i = 0 ; i <= n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;

    vector<int> v(n, -1);
    v[0] = 0;
    v[1] = 1;

    return 0;
}