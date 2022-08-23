#include "bits/stdc++.h"
using namespace std;

class Solution
{
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

public:
    int maxsize = 0, minsize = 0;
    // Function to insert heap.
    void insertHeap(int &x)
    {
        max.push(x);
        maxsize++;
        min.push(max.top());
        minsize++;
        max.pop();
        maxsize--;
        balanceHeaps();
    }
    // Function to balance heaps.
    void balanceHeaps()
    {
        if (minsize > maxsize)
        {
            max.push(min.top());
            maxsize++;
            min.pop();
            minsize--;
        }
    }
    // Function to return Median.
    double getMedian()
    {
        if (maxsize > minsize)
            return max.top();
        else
        {
            return (max.top() + min.top()) / 2.00;
        }
    }
};