#pragma once
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		bool bRetResult = false;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (m_set.find(nums[i]) == m_set.end())
			{
				m_set.insert(nums[i]);
			}
			else
			{
				return true;
			}
			
		}
		return bRetResult;
	}
	bool TestSolution() {
		bool bResult = false;
		vector<int> vecTest = { 1,2,3,4 };
		bool bValue = containsDuplicate(vecTest);

		bResult = true;
		return bResult;
	}
protected:
	std::set<int> m_set;
};