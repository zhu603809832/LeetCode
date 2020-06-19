#pragma once
#include <vector>
using namespace std;

#define NULL 0
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		bool bHasPath = false;
		if (NULL == root)
			return bHasPath;

		vector<int> vecSum;
		int nCurSum = 0;
		DFS(root, nCurSum, vecSum);
		for (int i = 0; i < vecSum.size(); ++i)
		{
			if (vecSum[i] == sum)
				return true;
		}
		return false;
	}
	bool DFS(TreeNode* pParent, int nCurSum, vector<int>& vecSum)
	{
		if (NULL == pParent)
			return true;

		nCurSum += pParent->val;
		if (NULL == pParent->left && NULL == pParent->right)
			vecSum.push_back(nCurSum);

		DFS(pParent->left, nCurSum, vecSum);
		DFS(pParent->right, nCurSum, vecSum);
		return true;
	}
	bool TestSolution() {
		bool bResult = false;
		/*TreeNode* pNode1 = new TreeNode(5);
		TreeNode* pNode2 = new TreeNode(4);
		TreeNode* pNode3 = new TreeNode(8);
		pNode1->left = pNode2;
		pNode1->right = pNode3;

		TreeNode* pNode4 = new TreeNode(11);
		pNode2->left = pNode4;

		TreeNode* pNode5 = new TreeNode(13);
		TreeNode* pNode6 = new TreeNode(4);
		pNode3->left = pNode5;
		pNode3->right = pNode6;

		TreeNode* pNode7 = new TreeNode(7);
		pNode4->left = pNode7;

		TreeNode* pNode8 = new TreeNode(2);
		pNode4->right = pNode8;

		TreeNode* pNode9 = new TreeNode(1);
		pNode6->right = pNode9;*/
		TreeNode* pNode1 = new TreeNode(1);
		TreeNode* pNode2 = new TreeNode(2);
		pNode1->left = pNode2;
		bool bHas = hasPathSum(pNode1, 2);
		bResult = true;
		return bResult;
	}
};