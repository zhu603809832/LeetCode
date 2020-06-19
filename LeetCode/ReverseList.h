#pragma once
//https://leetcode-cn.com/problems/reverse-linked-list/

#define NULL 0 

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseList(ListNode* pHead) {
		if (NULL == pHead)
			return NULL;

		if (NULL == pHead->next)
			return pHead;

		ListNode* pEnd = NULL;
		ListNode* pCurNode = pHead;
		while (pCurNode)
		{
			if (NULL == pCurNode->next)
				pEnd = pCurNode;

			pCurNode = pCurNode->next;
		}
		pCurNode = pHead;
		while (pCurNode)
		{
			ListNode* pNextNode = pCurNode->next;
			pCurNode->next = pEnd->next;
			pEnd->next = pCurNode;

			if (pNextNode == pEnd)
				break;

			pCurNode = pNextNode;
		}
		return pEnd;
	}
	bool testSolution() {
		ListNode* pNode1 = new ListNode(1);
		ListNode* pNode2 = new ListNode(2);
		ListNode* pNode3 = new ListNode(3);
		ListNode* pNode4 = new ListNode(4);
		ListNode* pNode5 = new ListNode(5);
		pNode1->next = pNode2;
		pNode2->next = pNode3;
		pNode3->next = pNode4;
		pNode4->next = pNode5;
		pNode5->next = NULL;
		ListNode* pReverse = reverseList(pNode1);
		return true;
	}
};

/*
public ListNode reverseList(ListNode head) {
ListNode prev = null;
ListNode curr = head;
while (curr != null) {
ListNode nextTemp = curr.next;
curr.next = prev;
prev = curr;
curr = nextTemp;
}
return prev;
}

作者：LeetCode
链接：https://leetcode-cn.com/problems/reverse-linked-list/solution/fan-zhuan-lian-biao-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/