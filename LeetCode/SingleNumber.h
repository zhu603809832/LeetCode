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


交换律：a ^ b ^ c <=> a ^ c ^ b

任何数于0异或为任何数 0 ^ n => n

相同的数异或为0: n ^ n => 0

var a = [2,3,2,4,4]

2 ^ 3 ^ 2 ^ 4 ^ 4等价于 2 ^ 2 ^ 4 ^ 4 ^ 3 => 0 ^ 0 ^3 => 3

*/