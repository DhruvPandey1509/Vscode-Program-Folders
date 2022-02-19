#include <iostream>
#include <unordered_map>
#include<map>
#include <iterator>
using namespace std;

int main()
{
    int a[] = {1, 3, 2, 2, 4, 2, 1, 6, 6};
    int n = sizeof(a) / sizeof(a[0]);
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }

    map<int, int>::iterator it;
    for (it = freq.begin(); it != freq.end(); it++)
    {
        cout<<it->first<<" "<<it->second<<endl;
    }
    freq[10] = 200;
    cout<<freq[10]<<endl;
    return 0;
}