#pragma once

#define NULL 0
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* pRetNode = NULL;
		if (NULL == headA || NULL == headB)
			return pRetNode;

		int nLengthA = 0;
		int nLengthB = 0;
		ListNode* pNode = headA;
		while (pNode)
		{
			++nLengthA;
			pNode = pNode->next;
		}

		pNode = headB;
		while (pNode)
		{
			++nLengthB;
			pNode = pNode->next;
		}
		int nDiffLength = nLengthA - nLengthB;
		ListNode* pLong = nDiffLength >= 0 ? headA : headB;
		ListNode* pShort = nDiffLength < 0 ? headA : headB;
		nDiffLength = nDiffLength > 0 ? nDiffLength : -nDiffLength;

		pNode = pLong;
		while (nDiffLength)
		{
			pNode = pNode->next;
			--nDiffLength;
		}
		ListNode* pNodeA = pNode;
		ListNode* pNodeB = pShort;
		while (pNodeA && pNodeB)
		{
			if (pNodeA == pNodeB)
			{
				pRetNode = pNodeA;
				return pRetNode;
			}
			pNodeA = pNodeA->next;
			pNodeB = pNodeB->next;
		}
		return pRetNode;
	}
	bool testSolution() {
		ListNode* pNode11 = new ListNode(4);
		ListNode* pNode12 = new ListNode(1);

		ListNode* pNode21 = new ListNode(5);
		ListNode* pNode22 = new ListNode(0);
		ListNode* pNode23 = new ListNode(1);

		ListNode* pNode33 = new ListNode(8);
		ListNode* pNode34 = new ListNode(4);
		ListNode* pNode35 = new ListNode(5);

		pNode11->next = pNode12;
		pNode12->next = pNode33;

		pNode21->next = pNode22;
		pNode22->next = pNode23;
		pNode23->next = pNode33;

		pNode33->next = pNode34;
		pNode34->next = pNode35;

		ListNode* pRet = getIntersectionNode(pNode11, pNode21);
		return true;
	}
};
/*
class Solution(object):
def getIntersectionNode(self, headA, headB):
ha, hb = headA, headB
while ha != hb:
ha = ha.next if ha else headB
hb = hb.next if hb else headA
return ha

作者：jyd
链接：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/intersection-of-two-linked-lists-shuang-zhi-zhen-l/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/