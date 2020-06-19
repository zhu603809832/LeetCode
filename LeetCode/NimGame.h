#pragma once
//https://leetcode-cn.com/problems/nim-game/
//#define MAX_NUM 100000

class Solution {
public:
	/*Solution() {
		memset(m_nWinValue, 0, sizeof(m_nWinValue));
		CalcCache();
	}

	bool CalcCache() {
		m_nWinValue[1] = 1;
		m_nWinValue[2] = 1;
		m_nWinValue[3] = 1;
		for (int i = 4; i <= MAX_NUM; ++i)
		{
			int nValue1 = InverseValue(m_nWinValue[i - 1]);
			int nValue2 = InverseValue(m_nWinValue[i - 2]);
			int nValue3 = InverseValue(m_nWinValue[i - 3]);
			m_nWinValue[i] = nValue1 || nValue2 || nValue3;
		}
		return true;
	}

	int InverseValue(int nValue) {
		return 1 - nValue;
	}*/

	bool canWinNim(int n) {
		bool Lose = n % 4 == 0;
		return !Lose;
	}

	bool testSolution() {
		int nValue1 = canWinNim(10);
		int nValue2 = canWinNim(5);
		int nValue3 = canWinNim(6);
		return true;
	}
//protected:
//	int m_nWinValue[MAX_NUM + 1];
};