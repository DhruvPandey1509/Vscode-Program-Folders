#include <iostream>
using namespace std;
//array is sorted and rotated with unknown pivot element.
int searchInRotatedArray(int *a, int key, int left, int right) //returns the index of the key if present else -1;
{
    if (left > right)
    {
        return -1;
    }

    int mid = left + (right - left) / 2;

    if (a[mid] == key)
    {
        return mid;
    }

    if (a[left] <= a[mid]) //checking if it is true and not the pivot point
    {
        if (key >= a[left] && key <= a[mid])
        {
            return searchInRotatedArray(a, key, left, mid - 1); //searching in the left half of the array
        }
        return searchInRotatedArray(a, key, mid + 1, right); //searching in the right half of the array
    }

    if (key >= a[mid] && key <= a[right])
    {
        return searchInRotatedArray(a, key, mid + 1, right); //searching in the right half of the array
    }
    return searchInRotatedArray(a, key, left, mid - 1); //searching in the left half of the array
}

int main()
{
    int a[] = {30, 40, 50, 10, 20};
    int key = 10;
    int right = sizeof(a) / sizeof(a[0]) - 1;
    cout << searchInRotatedArray(a, key, 0, right) << endl;

    return 0;
}