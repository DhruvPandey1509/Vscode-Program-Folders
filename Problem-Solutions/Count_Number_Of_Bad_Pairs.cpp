#include "bits/stdc++.h"
using namespace std;
/*
To find the bad pairs hum kya kr sakte hain we can think ulta like
total no of pairs =no of good pairs+ BAD PAIRS
toh BAD PAIRS =total -good
hum essa isliye kr rahain kyunki good pairs nikalna easy h ab wo kaise
yr good pairs kya honge jo bad nai h mtlb
i<j when j-i==nums[j]-nums[i] hoga
so we'ill rearrange it to get j-nums[j]==i-nums[i]
toh bas
hum ek ek krke array pe iterate karenge phir map main check karenge ki kya
i-nums[i] ki value present h ki nai agar nai h mtlb humara current no sabke saath bad pair banayega toh humare ans main uska index add ho jayega or agar
hogi toh humara current index un sabko chodke uske alawa jitte bhi no h un sabhi no ke saath pair krlega bas hum yahi karenge ek ek krke har i-nums[i] ka count badate jayenge map main or check krlenge
ki kya wo present h ki nai agar nai h toh direct index add or agar h toh index-uskacount add krdenge ans main
or phir ans return kr denge
*/

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {

        long long int res = 0;
        unordered_map<int, int> m;

        for (int i = 0; i < nums.size(); i++)
        {
            if (m.find(i - nums[i]) == m.end())
            {
                res += i; // it means it will not form pair with all the elements upto i
            }
            else
            {
                res += i - m[i - nums[i]]; 
            }

            m[i - nums[i]]++;
        }

        return res;
    }
};