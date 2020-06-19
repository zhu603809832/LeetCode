#pragma once
#include <vector>
using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		int nRetValue = 0;
		int nCount = nums.size();
		int nMajortyNum = nums[0];
		int nMajortyCount = 1;
		for (int i = 1; i < nCount; ++i)
		{
			if (nMajortyNum == nums[i])
				nMajortyCount++;
			else
				nMajortyCount--;

			if (nMajortyCount == 0)
			{
				nMajortyNum = nums[i];
				nMajortyCount = 1;
			}
		}
		nRetValue = nMajortyNum;
		return nRetValue;
	}
	bool TestSolution() {
		bool bResult = false;
		//vector<int> vecTest = { 2,2,1,1,1,2,2 };
		vector<int> vecTest = { 3,2,3 };
		int nValue = majorityElement(vecTest);
		bResult = true;
		return bResult;
	}
};