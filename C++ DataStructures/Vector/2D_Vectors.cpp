#include "bits/stdc++.h"
using namespace std;

int main()
{
    vector<vector<int>> v(5, vector<int>(2,1)); //5 = no.of rows;   2 = no of coloumns; 
    for(auto i : v)                            //the values are intialized to 1
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }

        cout<<endl;
    }                                             
    return 0;
}