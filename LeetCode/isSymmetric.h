#pragma once
#define NULL 0
#include <vector>
#include <queue>
using namespace std;
#define INVALID_FLAG 889312

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		std::queue<TreeNode* >queueIter;

		bool Result = false;
		if (NULL == root)
			return true;

		queueIter.push(root);
		int nLevelIndex = 0;
		while (queueIter.size())
		{
			int nSize = queueIter.size();
			std::vector<int >queueTreeValue;
			for (int i = 0; i < nSize; ++i)
			{
				TreeNode* pCurrent = queueIter.front();
				queueIter.pop();
				if (pCurrent)
					queueTreeValue.push_back(pCurrent->val);
				else
					queueTreeValue.push_back(INVALID_FLAG);

				if (pCurrent && pCurrent->left)
					queueIter.push(pCurrent->left);
				else
					queueIter.push(NULL);

				if (pCurrent && pCurrent->right)
					queueIter.push(pCurrent->right);
				else
					queueIter.push(NULL);

			}
			if (!IsSymmetricVector(queueTreeValue))
				return false;
			if (IsAllInValidFlag(queueTreeValue))
				return true;

		}
		return Result;

	}
	bool IsSymmetricVector(const vector<int> & vecInput)
	{
		bool bIsSymmetric = true;
		int nSize = vecInput.size();
		if (1 == nSize)
			return bIsSymmetric;

		for (int i = 0; i < nSize / 2; ++i)
		{
			bIsSymmetric = bIsSymmetric && (vecInput[i] == vecInput[nSize - 1 - i]);
		}
		return bIsSymmetric;
	}
	bool IsAllInValidFlag(const vector<int> & vecInput)
	{
		bool bIsValid = true;
		int nSize = vecInput.size();
		for (int i = 0 ; i < nSize; ++i)
		{
			bIsValid = bIsValid && (vecInput[i] == INVALID_FLAG);
		}
		return bIsValid;
	}
	bool TestSolution() {
		bool bResult = false;
		TreeNode* pNode1 = new TreeNode(1);
		TreeNode* pNode2 = new TreeNode(2);
		TreeNode* pNode3 = new TreeNode(2);
		pNode1->left = pNode2;
		pNode1->right = pNode3;
		
		pNode2->left = new TreeNode(3);
		pNode2->right = new TreeNode(4);

		pNode3->left = new TreeNode(4);
		pNode3->right = new TreeNode(3);
		bool bValue = isSymmetric(pNode1);
		bResult = true;
		return bResult;
	}
};

//public boolean isSymmetric(TreeNode root) {
//	Queue<TreeNode> q = new LinkedList<>();
//	q.add(root);
//	q.add(root);
//	while (!q.isEmpty()) {
//		TreeNode t1 = q.poll();
//		TreeNode t2 = q.poll();
//		if (t1 == null && t2 == null) continue;
//		if (t1 == null || t2 == null) return false;
//		if (t1.val != t2.val) return false;
//		q.add(t1.left);
//		q.add(t2.right);
//		q.add(t1.right);
//		q.add(t2.left);
//	}
//	return true;
//}
