#pragma once
//https://leetcode-cn.com/interview/2/
#include <vector>
using namespace std;
#define MAX_VALUE(a,b) a >= b ? a : b;
class Solution {
public:
	int jump(vector<int>& nums) {
		int nResult = 0;
		int nCount = nums.size();
		if (0 == nCount)
			return nResult;

		vector<int> vecMaxStepDistanceDP;
		vecMaxStepDistanceDP.resize(nCount);
		vecMaxStepDistanceDP[0] = 0;
		//vecMaxStepDistanceDP[i]�����ʶ�±�Ϊi��ʱ����Զ����
		vecMaxStepDistanceDP[1] = nums[0];
		for (int i = 1; i < nCount; ++i)
		{
			int nMaxDistance = INT_MIN;
			for (int j = i - 1; j >= 0; --j)
			{
				vecMaxStepDistanceDP[j] + 
			}
		}
	}
};

