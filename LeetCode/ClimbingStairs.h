#pragma once
//https://leetcode-cn.com/problems/climbing-stairs/
#include<vector>
using namespace std;
#define MAX(a, b) a >= b ? a : b;

class Solution {
public:
	int climbStairs(int n) {
		if (0 == n)
			return 0;

		int nResizeNum = n < 3 ? 3 : n + 1;
		int nRetValue = 0;
		vector<int> vecDP;
		vecDP.resize(nResizeNum);
		vecDP[0] = 0;
		vecDP[1] = 1;
		vecDP[2] = 2;
		for (size_t i = 3; i < n + 1; i++)
		{
			vecDP[i] = vecDP[i - 1] + vecDP[i - 2];
		}
		nRetValue = vecDP[n];
		return nRetValue;
	}
	bool testSolution() {
		int nValue1 = climbStairs(2);
		int nValue2 = climbStairs(5);
		int nValue3 = climbStairs(6);

		int nValue31 = climbStairs(10);
		return true;
	}
};