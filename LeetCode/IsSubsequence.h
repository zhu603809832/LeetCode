#pragma once
#include <string>
using namespace std;

class Solution {
public:
	bool isSubsequence(string s, string t) {
		bool bRetValue = false;
		int nShortCount = s.size();
		int nLongCount = t.size();
		if (0 == nShortCount)
			return true;

		if (0 == nLongCount)
			return bRetValue;
		
		int nBeginFindIndex = 0;
		for (int i = 0; i < nShortCount; ++i)
		{
			char strPattern = s[i];
			bool bFindFlag = false;
			for (int j = nBeginFindIndex; j < nLongCount; ++j)
			{
				char strTemp = t[j];
				if (strPattern == strTemp)
				{
					bFindFlag = true;
					nBeginFindIndex = j + 1;
					break;
				}
			}
			if (false == bFindFlag)
				return bRetValue;
		}

		bRetValue = true;
		return bRetValue;
	}
	bool testSolution() {
		bool bValue1 = isSubsequence("abc", "ahbgdc");
		bool bValue2 = isSubsequence("axc", "ahbgdc");
		return true;
	}
};