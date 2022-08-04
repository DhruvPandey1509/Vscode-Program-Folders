#include "bits/stdc++.h"
using namespace std;

class SmallestInfiniteSet
{
public:
    set<int> st; //  stores those numbers which are <val and present in the set
    int val;     // {st} union  {val,val+1,...,infinity} is the set

    SmallestInfiniteSet()
    {
        val = 1;
        st.clear();
    }

    int popSmallest()
    {
        if (st.size() > 0)
        {
            int poppedNum = *st.begin();
            st.erase(st.begin());
            return poppedNum;
        }

        val++;
        return val - 1;
    }

    void addBack(int num)
    {
        if (num < val and st.find(num) == st.end())
        {
            st.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */