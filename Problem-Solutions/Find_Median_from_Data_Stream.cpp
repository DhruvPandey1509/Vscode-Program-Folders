#include "bits/stdc++.h"
using namespace std;

class MedianFinder
{
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> min;

public:
    int maxsize = 0, minsize = 0;
    MedianFinder()
    {
    }
    void addNum(int num)
    {
        max.push(num);
        maxsize++;
        min.push(max.top());
        minsize++;
        max.pop();
        maxsize--;

        if (minsize > maxsize)
        {
            max.push(min.top());
            maxsize++;
            min.pop();
            minsize--;
        }
    }

    double findMedian()
    {
        if (maxsize > minsize)
            return max.top();
        else
            return (max.top() + min.top()) / 2.00;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */