#include "bits/stdc++.h"
using namespace std;
void solve()
{
    long long n;
    string s;

    cin>>n>>s;
    vector<int> prefix(n, 0), suffix(n, 0);
    set<char> st;
    for(int i = 0; i < n; i++)
    {
        st.insert(s[i]);
        prefix[i] = st.size();
    }
    st.clear();
    for(int i = n-1; i >= 0; i--)
    {
        st.insert(s[i]);
        suffix[i] = st.size();
    }

    int curr = 0, res = 0;
    for(int i = 0; i < n-1; i++)
    {
        curr = prefix[i] + suffix[i+1];
        res = max(curr, res);
    } 
    cout<<res<<endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}