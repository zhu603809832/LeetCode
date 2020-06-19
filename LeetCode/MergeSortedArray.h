#pragma once
//https://leetcode-cn.com/problems/merge-sorted-array/

#include <vector>
using namespace std;
#define DATA_HOLE 0
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int nInsertIndex = 0;
		for (int i = 0; i < n; ++i)
		{
			int nNum = nums2[i];
			for (; nInsertIndex < nums1.size(); ++nInsertIndex)
			{
				if (nums1[nInsertIndex] == DATA_HOLE)
				{
					nums1[nInsertIndex] = nNum;
					break;
				}
			}
		}
		BubbleSort(nums1);
	}
	void BubbleSort(vector<int>& nums) {
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i; j < nums.size(); ++j)
			{
				if (nums[i] > nums[j])
				{
					SwapValue(nums[i], nums[j]);
				}
			}
		}
	}
	void SwapValue(int& nValue1, int &nValue2) {
		int nTemp = nValue1;
		nValue1 = nValue2;
		nValue2 = nTemp;
	}

	bool testSolution() {
		
		int nums1[] = { -1, 0, 0, 3, 3, 3, 0, 0, 0 };
		int m = sizeof(nums1) / sizeof(nums1[0]);
		vector<int> vecNum1(nums1, nums1 + m);

		int num2[] = { 1, 2, 2 };
		int n = sizeof(num2) / sizeof(num2[0]);
		vector<int> vecNum2(num2, num2 + n);
		merge(vecNum1, 6, vecNum2, 3);
		return true;
	}
};