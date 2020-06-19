#pragma once
#define NULL 0
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if (NULL == node)
			return;
		ListNode* pCurNode = node;
		while (pCurNode)
		{
			ListNode* pNextNode = pCurNode->next;
			if (pNextNode)
			{
				pCurNode->val = pNextNode->val;
				if (NULL ==  pNextNode->next)
				{
					pCurNode->next = NULL;
					break;
				}
			}

			pCurNode = pCurNode->next;
		}
		return;
	}
	bool TestSolution() {
		bool bResult = false;
		ListNode* pNode1 = new ListNode(4);
		ListNode* pNode2 = new ListNode(5);
		ListNode* pNode3 = new ListNode(1);
		ListNode* pNode4 = new ListNode(9);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;
		deleteNode(pNode3);
		bResult = true;
		return bResult;
	}
};
