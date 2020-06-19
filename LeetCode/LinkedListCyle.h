#pragma once
//https://leetcode-cn.com/problems/linked-list-cycle/
#include <map>

//Definition for singly-linked list.
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode *head) {
		bool bIsHasCycle = false;
		ListNode* pNodeIter = head;
		while (pNodeIter)
		{
			if (m_mapIterRecord.find(pNodeIter) == m_mapIterRecord.end())
				m_mapIterRecord[pNodeIter] = true;
			else
			{
				bIsHasCycle = true;
				break;
			}
			pNodeIter = pNodeIter->next;
		}
		return bIsHasCycle;
	}
	bool testSolution() {
		ListNode* pNode1 = new ListNode(3);
		ListNode* pNode2 = new ListNode(2);
		ListNode* pNode3 = new ListNode(0);
		ListNode* pNode4 = new ListNode(-4);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;
		/*pNode4->next = pNode2;*/
		bool bValue = hasCycle(pNode1);
		return true;
	}
private:
	std::map<ListNode*, bool> m_mapIterRecord;

};
/*
//快慢指针解决判断是否有环
bool hasCycle(struct ListNode *head)
{
struct ListNode *slow = head;
struct ListNode *fast = head;

while(fast && fast->next)
{
slow = slow->next;
fast = fast->next->next;

if(slow == fast)
{
return true;
}
}
return false;
}*/