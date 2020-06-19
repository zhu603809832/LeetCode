#pragma once
//https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int nRetValue = 0;
		vector<int> maxProfitDP;
		if (prices.size() <= 1)
			return 0;

		maxProfitDP.resize(prices.size());
		maxProfitDP[0] = 0;
		maxProfitDP[1] = max(prices[1] - prices[0], maxProfitDP[0]);

		for (int i = 2; i < prices.size(); ++i)
		{
			int nMaxProfit = 0;
			for (int j = i - 1; j >= 0; --j )
			{
				int nBeforeMaxProfitDP = j - 1 >= 0 ? maxProfitDP[j - 1] : 0;
				int nTemp = prices[i] - prices[j] + nBeforeMaxProfitDP;
				if (nTemp > nMaxProfit)
				{
					nMaxProfit = nTemp;
				}
			}
			maxProfitDP[i] = max(maxProfitDP[i - 1], nMaxProfit);
		}
		nRetValue = maxProfitDP[prices.size() - 1];
		return nRetValue;
	}

	bool testSolution() {
		vector<int> prices;
		prices.push_back(1);
		prices.push_back(2);
		prices.push_back(3);
		prices.push_back(4);
		prices.push_back(5);

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

		prices.clear();
		prices.push_back(7);
		prices.push_back(6);
		prices.push_back(4);
		prices.push_back(3);
		prices.push_back(1);
		prices.push_back(2);
		int nValue4 = maxProfit(prices);

		return true;
	}
};