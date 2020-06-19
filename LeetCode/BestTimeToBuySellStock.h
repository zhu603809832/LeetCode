#pragma once
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/

#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() <= 1)
			return 0;

		vector<int> vecDP;
		vecDP.resize(prices.size());
		vecDP[0] = 0;
		vecDP[1] = 0;
		int nMinPrice = INT_MAX;
		for (int i = 0; i < prices.size(); ++i)
		{
			if (prices[i] < nMinPrice)
				nMinPrice = prices[i];

			if (i - 1 >= 0)
				vecDP[i] = max(vecDP[i - 1], prices[i] - nMinPrice);
		}
		int nRetResult = vecDP[prices.size() - 1];
		return nRetResult;
	}

	bool testSolution() {
		vector<int> prices; 
		prices.push_back(7);
		prices.push_back(6);
		prices.push_back(4);
		prices.push_back(3);
		prices.push_back(1);
		
		int nValue1 = maxProfit(prices);

		prices.clear();
		prices.push_back(7);
		prices.push_back(1);
		prices.push_back(5);
		prices.push_back(3);
		prices.push_back(6);
		prices.push_back(4);
		int nValue2 = maxProfit(prices);

		prices.clear();
		prices.push_back(1);
		prices.push_back(2);
		int nValue3 = maxProfit(prices);

		return true;
	}
};