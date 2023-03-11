#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    string str = "";
    for(int i = 1; i <= 50; i++)
    {
        if(i%3==0) str+='F';
        if(i%5==0) str+='B';
    }

    while (t--)
    {
        int n;
        cin >> n;
        if (n > 10 || n <= 0)
        {
            cout << "NO" << endl;
            continue;
        }
        string s;
        cin >> s;
        bool flag = false;
        for (int i = 0; i <= 8; i++)
        {
            if(str.substr(i, n) == s)
            {
                cout<<"YES"<<endl;
                flag = true;
                break;
            }
        }
        if (!flag)
            cout << "NO" << endl;
    }
    return 0;
}