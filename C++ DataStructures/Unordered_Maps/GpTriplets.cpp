#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int count_triplets(vector<int> arr, int r)
{
    int n = arr.size();

    unordered_map<long,long> right, left; //key is the element of the array, and Value is its frequency 
    //Init the Right Map with Freq, Left map = 0
    for(auto x : arr)
    {
        right[x]++;
        left[x] = 0;
    }
    //compute by iterating from left to right
    int ans = 0;
    for(int i = 0 ; i < n; i++)
    {
        right[arr[i]]--;
        if(arr[i]%r == 0)
        {
            long a = arr[i]/r; //a is the element a/r on left of the current element
            long b = arr[i];   //b is the current element
            long c = arr[i]*r;  //c is the element ar on right of the curr element

            ans += left[a] * right[c];   //left[a] : freq of a/r on left, right[c] : freq of element ar on right
        }
        left[arr[i]]++;
    }

    return ans;
}

int main()
{
    int n, r;
    cin >> n >> r;
    vector<int> arr(n, 0);
    for (auto &i : arr)
    {
        cin >> i;
    }

    cout<<count_triplets(arr,r)<<endl;
    return 0;
}