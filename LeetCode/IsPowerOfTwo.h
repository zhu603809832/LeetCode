#pragma once
#include <map>

class Solution {
public:
	Solution() {
		const int nMaxStep = 32;
		for (int i = 0; i < nMaxStep; ++i)
		{
			m_IsPowOfTwo[1 << i] = true;
		}
	}
	bool isPowerOfTwo(int n) {
		if (n < 0)
			return false;

		return m_IsPowOfTwo[n];
	}

	bool testSolution() {
		bool bValue1 = isPowerOfTwo(1024);
		bool bValue2 = isPowerOfTwo(1025);
		bool bValue3 = isPowerOfTwo(2048);
		bool bValue4 = isPowerOfTwo(-16);
		bool bValue5 = isPowerOfTwo(2);
		return true;
	}
	std::map<int, bool>m_IsPowOfTwo;
};

/*
class Solution {
public:
   bool isPowerOfTwo(int n) {
	if (n<=0)
		return false;
	if((n&(n-1))==0)
		 return true;
	return false;
}
};

作者：varyshare
链接：https://leetcode-cn.com/problems/power-of-two/solution/gao-xiao-suan-fa-ji-bai-100de-yong-hu-by-varyshare/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

/*
class Solution {
public:
   bool isPowerOfTwo(int n) {
	if (n<=0)
		return false;
	while (n != 0) {
		if (n & 1 != 0)// 判断是否末位是1
		{
			if (n == 1)
				return true;
			else
				return false;
		}
		n = n >> 1;
	}
	return true;
}
};

作者：varyshare
链接：https://leetcode-cn.com/problems/power-of-two/solution/gao-xiao-suan-fa-ji-bai-100de-yong-hu-by-varyshare/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/