#include"bits/stdc++.h"
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int t) {
        
    vector<pair<int, int>> v;
	for(int i = 0 ; i < nums.size(); i++)
	{
		v.push_back(make_pair(nums[i],i));
	}
	sort(v.begin(), v.end());
	int st = 0;
	int en = nums.size()-1; //end pointer
	int sum = 0;
    vector<int> v1;
	while(st < en)
	{
		sum = v[st].first + v[en].first;

		if(sum == t)
		{
           v1.push_back(v[st].second);
		   v1.push_back(v[en].second);
		   break;
		}

		else if(sum > t)
		{
			en--;
		}
		else if(sum < t)
		{
			st++;
		}
	}
	return v1;
        
    }
    
    
};