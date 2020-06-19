#pragma once
//https://leetcode-cn.com/problems/maximum-subarray/
#include <vector>

#define MAX(a, b) a >= b ? a : b;
using namespace std;

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int nRetValue = 0;
		if (0 == nums.size())
			return nRetValue;

		vector<int> maxSubValueDP;
		maxSubValueDP.resize(nums.size());
		maxSubValueDP[0] = nums[0];
		int nMaxValue = INT_MIN;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (i - 1 >= 0)
				maxSubValueDP[i] = MAX(maxSubValueDP[i - 1] + nums[i], nums[i]);
			if (maxSubValueDP[i] > nMaxValue)
				nMaxValue = maxSubValueDP[i];
		}
		nRetValue = nMaxValue;
		return nRetValue;

	}
	bool testSolution()
	{
		vector<int> testVec;
		testVec.push_back(-2);
		testVec.push_back(1);
		testVec.push_back(-3);
		testVec.push_back(4);
		testVec.push_back(-1);
		testVec.push_back(2);
		testVec.push_back(1);
		testVec.push_back(-5);
		testVec.push_back(4);
		int nValue = maxSubArray(testVec);
		return true;
	}
};