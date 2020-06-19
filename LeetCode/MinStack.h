#pragma once
#include <stack>
using namespace std;

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		m_curStack.push(x);
		if (m_minStack.empty())
			m_minStack.push(x);
		else
		{
			int nCurMin = m_minStack.top();
			if (x <= nCurMin)
				m_minStack.push(x);
		}
	}

	void pop() {
		int nTopValue = m_curStack.top();
		m_curStack.pop();
		int nTopMinValue = m_minStack.top();
		if (nTopValue == nTopMinValue)
			m_minStack.pop();

	}

	int top() {
		int nTop = m_curStack.top();
		return nTop;
	}

	int getMin() {
		int nTopMin = m_minStack.top();
		return nTopMin;
	}
private:
	stack<int> m_curStack;
	stack<int> m_minStack;
public:
	bool TestSolution() {
		bool bResult = false;
		push(1);
		push(-1);
		push(-2);
		push(0);
		int nMinValue = getMin();
		int nTop = top();
		pop();
		pop();
		nMinValue = getMin();
		nTop = top();

		bResult = true;
		return bResult;
	}
};

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->getMin();
*/