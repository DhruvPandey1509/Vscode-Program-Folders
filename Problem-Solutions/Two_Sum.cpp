#include "bits/stdc++.h"
using namespace std;

class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int t)
	{
		vector<pair<int, int>> v;
		for (int i = 0; i < nums.size(); i++)
		{
			v.push_back(make_pair(nums[i], i));
		}
		sort(v.begin(), v.end());
		int st = 0;
		int en = nums.size() - 1; // end pointer
		int sum = 0;
		vector<int> v1;
		while (st < en)
		{
			sum = v[st].first + v[en].first;

			if (sum == t)
			{
				v1.push_back(v[st].second);
				v1.push_back(v[en].second);
				break;
			}
			else if (sum > t)
			{
				en--;
			}
			else if (sum < t)
			{
				st++;
			}
		}
		return v1;
	}
};

// Better , faster and more efficient Approach using Hasmap
class Solution
{
public:
	vector<int> twoSum(vector<int> &nums, int t)
	{

		unordered_map<int, int> m; // key = nums[index]    val = index

		for (int i = 0; i < nums.size(); i++)
		{
			if (m.count(t - nums[i])) // checks whether number other then nums[i] whith who sum would be equal to target is present in the map or not;
			{
				return {i, m[t - nums[i]]}; // returns the index of the numbers
			}
			else
			{
				m[nums[i]] = i;
			}
		}

		return {};
	}
};