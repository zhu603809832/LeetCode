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

���ߣ�varyshare
���ӣ�https://leetcode-cn.com/problems/power-of-two/solution/gao-xiao-suan-fa-ji-bai-100de-yong-hu-by-varyshare/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/

/*
class Solution {
public:
   bool isPowerOfTwo(int n) {
	if (n<=0)
		return false;
	while (n != 0) {
		if (n & 1 != 0)// �ж��Ƿ�ĩλ��1
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

���ߣ�varyshare
���ӣ�https://leetcode-cn.com/problems/power-of-two/solution/gao-xiao-suan-fa-ji-bai-100de-yong-hu-by-varyshare/
��Դ�����ۣ�LeetCode��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
*/