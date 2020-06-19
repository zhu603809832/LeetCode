#pragma once
#include <iostream>
#include <vector>
#include <stack>
#define NULL 0
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode * lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode * pTreeNode = NULL;
		vector<TreeNode* > vecTraverP;
		vector<TreeNode* > vecTraverQ;
		m_vecTraverP.clear();
		m_vecTraverQ.clear();
		/*DFS(root, p, vecTraverP, m_vecTraverP);
		DFS(root, q, vecTraverQ, m_vecTraverQ);*/
		DFSStack(root, p, m_vecTraverP);
		DFSStack(root, q, m_vecTraverQ);
		int nSize = m_vecTraverP.size() < m_vecTraverQ.size() ? m_vecTraverP.size() : m_vecTraverQ.size();
		for (int i = 0; i < nSize; ++i)
		{
			TreeNode* pP = m_vecTraverP[i];
			TreeNode* pQ = m_vecTraverQ[i];
			if (pP == pQ)
			{
				pTreeNode = pP;
			}
			else
				break;
		}
		return pTreeNode;

	}
	void DFSStack(TreeNode* pRoot, TreeNode* pTarget, vector<TreeNode*> & vecRet)
	{
		if (NULL == pRoot)
			return;

		stack<TreeNode*> stlTreeNodeStack;
		stack<int> stlTreeNodeCurPathIndex;
		stlTreeNodeStack.push(pRoot);
		stlTreeNodeCurPathIndex.push(0);
		while (!stlTreeNodeStack.empty())
		{
			TreeNode* pCurTreeNode = stlTreeNodeStack.top();
			stlTreeNodeStack.pop();
			int nPathIndex = stlTreeNodeCurPathIndex.top();
			stlTreeNodeCurPathIndex.pop();
			if (nPathIndex >= vecRet.size())
				vecRet.push_back(pCurTreeNode);
			else
				vecRet[nPathIndex] = pCurTreeNode;

			if (pTarget == pCurTreeNode)
				break;

			if (pCurTreeNode->right)
			{
				stlTreeNodeStack.push(pCurTreeNode->right);
				stlTreeNodeCurPathIndex.push(nPathIndex + 1);
			}

			if (pCurTreeNode->left)
			{
				stlTreeNodeStack.push(pCurTreeNode->left);
				stlTreeNodeCurPathIndex.push(nPathIndex + 1);
			}
		}
		return;
	}

	void DFS(TreeNode* pParent, TreeNode* pTarget, vector<TreeNode* > vecDFS, vector<TreeNode*> & vecRet)
	{
		if (NULL == pParent)
			return;

		vecDFS.push_back(pParent);
		if (pTarget == pParent)
			vecRet = vecDFS;

		DFS(pParent->left, pTarget, vecDFS, vecRet);
		DFS(pParent->right, pTarget, vecDFS, vecRet);
		return;
	}
	bool TestSolution() {
		bool bResult = false;

		TreeNode* pNode1 = new TreeNode(3);
		TreeNode* pNode2 = new TreeNode(5);
		TreeNode* pNode3 = new TreeNode(1);
		pNode1->left = pNode2;
		pNode1->right = pNode3;

		TreeNode* pNode4 = new TreeNode(6);
		TreeNode* pNode5 = new TreeNode(2);
		pNode2->left = pNode4;
		pNode2->right = pNode5;

		TreeNode* pNode6 = new TreeNode(0);
		TreeNode* pNode7 = new TreeNode(8);
		pNode3->left = pNode6;
		pNode3->right = pNode7;

		TreeNode* pNode8 = new TreeNode(7);
		TreeNode* pNode9 = new TreeNode(4);
		pNode5->left = pNode8;
		pNode5->right = pNode9;
		TreeNode* pNode = lowestCommonAncestor(pNode1, pNode2, pNode5);
		bResult = true;
		return bResult;
	}
protected:
	vector<TreeNode* > m_vecTraverP;
	vector<TreeNode* > m_vecTraverQ;
};