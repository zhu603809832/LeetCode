#pragma once
//https://leetcode-cn.com/problems/reverse-integer/
//2,147,483,647 == 2^31 - 1
//-2,147,483,648 == 2^31

#define MAX_INT_VALUE_POSITIVE 2147483647
#define MAX_INT_VALUE_NEGATIVE_ABS 2147483648
class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return 0;

		if (x == -2147483648)
			return 0;

		int nSigned = x > 0 ? 1 : -1;
		//在abs里面不加强制类型转换时，会报错，因为有符号整形变量的范围是-2147483648    2147483647
		//当 - 2147483648取绝对值时大于2147483647就会报错，所以先对负数进行强制类型转换。
		int nAbsValue = x > 0 ? x : -static_cast<long long>(x);
		int nRetValue = 0;
		while (nAbsValue)
		{
			int nTemp = nAbsValue % 10;
			if (nSigned > 0)
			{
				int nLimit = MAX_INT_VALUE_POSITIVE / 10;
				int nLimitLeft = MAX_INT_VALUE_POSITIVE % 10;
				if (nRetValue > nLimit)
					return 0;
				else if (nRetValue == nLimit)
				{
					if (nTemp > nLimitLeft)
						return 0;
				}
			}
			else
			{
				int nLimit = MAX_INT_VALUE_NEGATIVE_ABS / 10;
				int nLimitLeft = MAX_INT_VALUE_NEGATIVE_ABS % 10;
				if (nRetValue > nLimit)
					return 0;
				else if (nRetValue == nLimit)
				{
					if (nTemp > nLimitLeft)
						return 0;
				}
			}
			nRetValue = nRetValue * 10 + nTemp;
			nAbsValue = nAbsValue / 10;
		}
		nRetValue = nRetValue * nSigned;
		return nRetValue;
	}

	bool TestSolution() {
		bool bResult = false;
		int nValue1 = reverse(123);
		int nValue2 = reverse(-123);
		int nValue3 = reverse(120);
		int nValue4 = reverse(2147483647);
		int nValue5 = reverse(2147483648);
		int nValue6 = reverse(-2147483648);
		bResult = true;
		return bResult;
	}
};