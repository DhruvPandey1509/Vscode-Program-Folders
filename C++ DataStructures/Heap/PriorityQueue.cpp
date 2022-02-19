#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int arr[] = {10,15,20,13,6,90};
    int n = sizeof(arr)/sizeof(arr[0]); 
    priority_queue<int> maxheap;

    for(auto x : arr)
    {
        maxheap.push(x);
    }
    while(!maxheap.empty())
    {
        cout<<maxheap.top()<<" ";
        maxheap.pop();
    }
    cout<<endl;
    priority_queue<int, vector<int>, greater<int>> minheap;
    for(auto x : arr)
    {
        minheap.push(x);
    }
    while(!minheap.empty())
    {
        cout<<minheap.top()<<" ";
        minheap.pop();
    }
    return 0;
}