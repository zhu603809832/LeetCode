#pragma once
//https://leetcode-cn.com/problems/house-robber/
#include <vector>
#define MAX(a, b) a >= b ? a : b;
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		int nRetValue = 0;
		if (0 == nums.size())
			return nRetValue;

		if (1 == nums.size())
			return nums[0];

		vector<int> maxRobberValue;
		maxRobberValue.resize(nums.size());
		maxRobberValue[0] = nums[0];
		maxRobberValue[1] = MAX(maxRobberValue[0], nums[1]);

		for (int i = 2; i < nums.size(); ++i)
		{
			maxRobberValue[i] = MAX(maxRobberValue[i - 2] + nums[i], maxRobberValue[i - 1]);
		}
		nRetValue = maxRobberValue[nums.size() - 1];
		return nRetValue;
	}
};