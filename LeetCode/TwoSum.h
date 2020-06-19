#pragma once
//https://leetcode-cn.com/problems/two-sum/

#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> vecRetResult;

		int nNumSize = nums.size();
		for (int i = 0; i < nNumSize; i++)
		{
			for (int j = i + 1; j < nNumSize; j++)
			{
				if (nums[i] + nums[j] == target)
				{
					vecRetResult.push_back(i);
					vecRetResult.push_back(j);
				}
			}
		}
		return vecRetResult;
	}
	bool TestSolution() {
		bool bResult = false;
		vector<int> nums = { 2, 7, 11, 15 };
		int nTarget = 9;
		vector<int> retResult = twoSum(nums, nTarget);

		bResult = true;
		return bResult;
	}
};