#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int lower_bound(vector<int> arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}
int upper_bound(vector<int> arr, int key)
{
    int s = 0;
    int e = arr.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = (s + e) / 2;

        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }

    return ans;
}
inline int frequency(vector<int> arr, int key)
{
    return upper_bound(arr, key) - lower_bound(arr, key) + 1;
}
int main()
{
    // vector<int> arr = {0, 1, 1, 2, 2, 3, 3, 3, 3, 4, 5, 5, 5, 10};
    vector<int> arr = {0, 0, 1, 1, 2, 2, 3};
    int n = arr.size();

    cout << lower_bound(arr, 2) << endl;
    cout << upper_bound(arr, 2) - lower_bound(arr, 2) + 1 << endl;
    cout<< upper_bound(arr.begin(), arr.end(), 2) - lower_bound(arr.begin(), arr.end(), 2)<<endl; //using stl for upper and lower bound
    return 0;                               //stl upperbound returns 1 index higher then the upper bound
}                                           //stl lowerbound returns the same index as of lower bound