#include"bits/stdc++.h"
using namespace std;

int main()
{
    int t;
    cin>>t;
    int j = 1;
    while (t--)
    {
        long long r, c;
        cin>>r>>c;
        long long ans = 0;
        r--, c--;
        long long i = 1;
        while(r != 0 && c != 0)
        {
            ans += r*c*i;
            i++;
            r--;
            c--;
        }

        cout<<"Case #"<<j<<": "<<ans<<endl;
        j++;
    }
    

    return 0;
}