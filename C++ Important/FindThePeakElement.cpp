#include<iostream>
#include<algorithm>
using namespace std;

int findPeakElement(int *a, int low, int high, int n)
{
    int mid = low + (high - low)/2;

    //if mid value is greater then its previous and next value. Also if mid is 0 we will not check for mid-1 as it will not exits,
    //similary is mid = n-1 then we will not check for mid+1 which will also not exit :. we included it in brackets with OR condition.
    if((mid == 0 || a[mid-1] <= a[mid]) && (mid == n-1 || a[mid+1] <= a[mid]))
    {
        return mid;
    }

    // if mid is greater then 0 and a[mid] < a[mid-1] then we will check in left half
    else if(mid > 0 && a[mid-1] > a[mid])
    {
        return findPeakElement(a,low,mid-1,n);
    }

    // if mid is greater then 0 and a[mid] < a[mid+1] then we will check in right half
    else
    {
        return findPeakElement(a,mid+1,high,n);
    }
}

int main()
{
    int a[] = {0,6,8,5,7,9};
    int n = 6;

    cout<<"Peak element index : "<<findPeakElement(a,0,n-1,n)<<endl;
    return 0;
}