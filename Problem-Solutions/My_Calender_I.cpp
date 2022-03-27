#include "bits/stdc++.h"
using namespace std;

class MyCalendar
{
    multiset<pair<int, int>> p;

public:
    MyCalendar()
    {
    }
    bool book(int start, int end)
    {
        p.insert({start, 1});
        p.insert({end, -1});

        int book = 0;

        for (auto it : p)
        {
            book += it.second;
            if (book > 1)
            {
                p.erase(p.find({start, 1}));
                p.erase(p.find({end, -1}));
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */