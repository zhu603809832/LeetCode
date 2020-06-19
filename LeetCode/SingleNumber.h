#pragma once
//https://leetcode-cn.com/problems/single-number/
#include <vector>
using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int nRetValue = 0;
		for (int i = 0; i < nums.size(); ++i)
		{
			nRetValue ^= nums[i];
		}

		return nRetValue;
	}
	bool testSolution()
	{
		int nArray[] = { 2,2,1 };
		vector<int> nums(nArray, nArray + sizeof(nArray) / sizeof(nArray[0]));
		int nRetValue = singleNumber(nums);
		return nRetValue;
	}
};

/*


�����ɣ�a ^ b ^ c <=> a ^ c ^ b

�κ�����0���Ϊ�κ��� 0 ^ n => n

��ͬ�������Ϊ0: n ^ n => 0

var a = [2,3,2,4,4]

2 ^ 3 ^ 2 ^ 4 ^ 4�ȼ��� 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3

*/