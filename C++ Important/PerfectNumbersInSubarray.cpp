#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isPerfect(int n)
{
    int sum = 1;
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n == n / i)
            {
                sum += i;
            }
            else
            {
                sum += i + n / i;
            }
        }
    }

    if (sum == n && n != 1)
    {
        return true;
    }

    return false;
}

int perfectNumber(vector<int> v, int k)
{
    if(v.size() < k)
    {
        cout<<"Not Valid"<<endl;
        return -1;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (isPerfect(v[i]))
        {
            v[i] = 1;
        }
        else
        {
            v[i] = 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    int ans = sum;
    for (int i = k; i < v.size(); i++)
    {
        sum += v[i] - v[i - k];
        ans = max(ans, sum);
    }

    return ans;
}

int main()
{
    vector<int> v = {28, 2, 3, 6};//, 496, 99, 8128, 24}
    int k = 4;
    cout << perfectNumber(v, 4 ) << endl;
    return 0;
}