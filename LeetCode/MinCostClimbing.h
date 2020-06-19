#pragma once
//https://leetcode-cn.com/problems/min-cost-climbing-stairs/
#include <vector>
using namespace std;
#define MIN(a, b) a <= b ? a : b;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int nRetValue = 0;
		int nCount = cost.size();
		vector<int> minCostDP;
		minCostDP.resize(nCount);

		if (0 == nCount)
			return nRetValue;

		if (1 == nCount)
			return cost[0];

		minCostDP[0] = cost[0];
		minCostDP[1] = cost[1];
		for (int i = 2; i < nCount; ++i)
		{
			minCostDP[i] = MIN(minCostDP[i - 1] + cost[i], minCostDP[i - 2] + cost[i]);
		}
		nRetValue = MIN(minCostDP[nCount - 1], minCostDP[nCount - 2]);
		return nRetValue;
	}
	bool testSolution()
	{
		vector<int> testCost;

		testCost.clear();
		testCost.push_back(10);
		testCost.push_back(15);
		testCost.push_back(20);
		int nValue1 = minCostClimbingStairs(testCost);

		testCost.clear();
		testCost.push_back(1);
		testCost.push_back(100);
		testCost.push_back(1);
		testCost.push_back(1);
		testCost.push_back(1);
		testCost.push_back(100);
		testCost.push_back(1);
		testCost.push_back(1);
		testCost.push_back(100);
		testCost.push_back(1);
		int nValue2 = minCostClimbingStairs(testCost);
		return true;
	}
};
