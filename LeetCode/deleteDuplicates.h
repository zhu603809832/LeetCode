#pragma once

#define NULL 0

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}

};

class Solution {
public:
	ListNode * deleteDuplicates(ListNode* head) {
		ListNode* pRetNode = NULL;
		if (NULL == head)
			return NULL;

		ListNode* pCurNode = head;
		while (pCurNode)
		{
			ListNode* pNextNode = pCurNode->next;
			if (pNextNode)
			{
				if (pCurNode->val == pNextNode->val)
				{
					ListNode* pCurNewNext = pNextNode;
					while (pCurNewNext)
					{
						if (pCurNewNext->val != pCurNode->val)
							break;
						pCurNewNext = pCurNewNext->next;
					}
					pCurNode->next = pCurNewNext;
				}
			}
			pCurNode = pCurNode->next;
		}
		pRetNode = head;
		return pRetNode;
	}
	bool TestSolution() {
		bool bResult = false;
		ListNode* pNode1 = new ListNode(1);
		ListNode* pNode2 = new ListNode(1);
		ListNode* pNode3 = new ListNode(2);	
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		ListNode* pRet = deleteDuplicates(pNode1);

		ListNode* pNodeA = new ListNode(1);
		ListNode* pNodeB = new ListNode(1);
		ListNode* pNodeC= new ListNode(1);

		
		pNodeA->next = pNodeB;
		pNodeB->next = pNodeC;
		pNodeC->next = new ListNode(2);
		ListNode* pRet2 = deleteDuplicates(pNodeA);

		bResult = true;
		return bResult;
	}
};