#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<pair<int, int>> v;
        int left = 0, right = 0, centre = 0;
        for(int i = 0; i < n; i++)
        {
            int l, r;
            cin>>l>>r;
            if(l == r && l == k) centre++;
            else if(l == k) left++;
            else if(r == k) right++;
        }
        if(centre > 0) cout<<"YES"<<endl;
        else if(left > 0 and right > 0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}