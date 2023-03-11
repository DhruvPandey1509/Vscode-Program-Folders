#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string a, b, fir = "", sec = "";
        int n1, n2;
        cin >> a >> b;
        n1 = a.size();
        n2 = b.size();
        for (int i = 0; i < (n1 - 1); i++)
        {
            for (int j = 0; j < (n2 - 1); j++)
            {
                if (a[i] == b[j] and a[i + 1] == b[j + 1])
                {
                    fir = a[i];
                    sec = a[i + 1];
                    break;
                }
            }
            if (fir != "")
                break;
        }
        if (fir != "")
        {
            cout << "YES" << endl;
            cout << "*" << fir << sec << "*" << endl;
        }
        else
        {
            if (a[0] == b[0])
            {
                cout << "YES" << endl;
                cout << a[0] << "*" << endl;
            }
            else if (a[n1 - 1] == b[n2 - 1])
            {
                cout << "YES" << endl;
                cout << "*" << a[n1 - 1] << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}