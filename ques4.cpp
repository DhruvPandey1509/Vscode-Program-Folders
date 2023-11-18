#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    map<int, int> m;
    for(auto &i : v)
    {
        cin>>i;
        m[i]++;
    }
    int count = 0;
    int k;
    cin>>k;
    for(int i = 0; i < n; i++)
    {
        if(m.find(abs(k - v[i])) != m.end()) count++;
    }
    return 0;
}