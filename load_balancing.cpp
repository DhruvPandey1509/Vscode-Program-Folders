#include<bits/stdc++.h>
using namespace std;
vector<int> getServerIndex(int n, int m, vector<int> &at, vector<int> &bt)
{
    vector<int> index(m);
    int currTime = 0;
    map<int, int> mp;
    for(int i = 0 ; i < m; i++)
    {
        currTime = at[i];
        if(mp.size() == n)
        {
            index[i] = -1;
        }
        
    }
}
int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> arrivalTime(m), burstTime(m);
    for(int i = 0 ; i < m; i++)
    {
        cin>>arrivalTime[i]>>burstTime[i];
    }
    vector<int> index = getServerIndex(n, m, arrivalTime, burstTime);
    return 0;
}