#include"bits/stdc++.h"
using namespace std;

void computeNumberFromSubarray(vector<int> arr, int k)
{
    int sum = 0;
    pair<int, int> ans;
    for(int i = 0 ; i < k ; i++)
    {
        sum += arr[i];
    }

    bool found = false;
    if(sum %3 == 0)
    {
        ans = make_pair(0, k-1);
        found = true;
    }

    for(int j = k ; j < arr.size(); j++)
    {
        if(found)
        {
            break;
        }
        sum = sum + arr[j] - arr[j-k];

        if(sum%3 == 0)
        {
            ans = make_pair(j-k+1, j);
            found = true;
        }
    }

    if(!found)
    {
        ans = make_pair(-1,0);
        cout<<"No such subarray exists."<<endl;
        return;
    }
    else
    {
        for(int i = ans.first; i <= ans.second ;i++)
        {
            cout<<arr[i];
        }
        cout<<endl;
    }
    
    return;

}

int main()
{
    vector<int> v = {84,23,45,12,56,82};
    int k = 3;

    computeNumberFromSubarray(v,k);  

    return 0;
}