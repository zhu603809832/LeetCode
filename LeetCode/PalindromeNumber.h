#pragma once
//https://leetcode-cn.com/problems/palindrome-number/
#include<vector>
class Solution {
public:

	bool isPalindrome(int x) {
		std::vector<int> vecValueNum;
		bool bResult = false;
		if (x < 0)
			return bResult;

		if (x == 0)
			return true;

		while (x)
		{
			int nTemp = x % 10;
			x = x / 10;
			vecValueNum.push_back(nTemp);
		}
	
		bResult = true;
		int nLastIndex = vecValueNum.size() - 1;
		for (size_t i = 0; i < vecValueNum.size() / 2; i++)
		{
			bResult = bResult && (vecValueNum[i] == vecValueNum[nLastIndex - i]);
		}
		return bResult;
	}

	bool TestSolution() {
		bool bResult = false;
		bool bValue1 = isPalindrome(121);
		bool bValue2 = isPalindrome(-121);
		bool bValue3 = isPalindrome(10);

		bResult = true;
		return bResult;
	}
};