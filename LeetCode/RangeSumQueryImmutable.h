#pragma once
//https://leetcode-cn.com/problems/range-sum-query-immutable/
#include <vector>
using namespace std;

class NumArray {
public:
	NumArray() {

	}
	NumArray(vector<int>& nums) {
		int nCount = nums.size();
		m_RangeValue.resize(nCount);

		for (int i = 0; i < nCount; ++i)
		{
			m_RangeValue[i].resize(nCount);
		}
		
		for (int i = 0; i < nCount; ++i)
		{
			m_RangeValue[i][i] = nums[i];
		}

		for (int i = 0; i < nCount; ++i)
		{
			for (int j = i + 1; j < nCount; ++j)
			{
				m_RangeValue[i][j] = m_RangeValue[i][j - 1] + nums[j];
			}
		}
	}

	int sumRange(int i, int j) {
		return m_RangeValue[i][j];
	}
	bool testSolution() {
		std::vector<int> nums;
		nums.push_back(-2);
		nums.push_back(0);
		nums.push_back(3);
		nums.push_back(-5);
		nums.push_back(2);
		nums.push_back(-1);
		NumArray* obj = new NumArray(nums);
		int param_1 = obj->sumRange(0, 2);
		int param_2 = obj->sumRange(2, 5);
		int param_3 = obj->sumRange(0, 5);
		return true;
	}
protected:
	std::vector< std::vector<int> > m_RangeValue;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */