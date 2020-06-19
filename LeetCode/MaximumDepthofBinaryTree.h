#pragma once
//https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
#include <vector>
#include <stack>
#include <iostream>
#define NULL 0
using namespace std;

//* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int nMaxDepth = 0;
		if (NULL == root)
			return 0;
		
		/*nMaxDepth = 1;
		m_stackIteration.push(root);
		while (m_stackIteration.size())
		{
			TreeNode* pCurNodel = m_stackIteration.top();
			m_stackIteration.pop();

			if (pCurNodel->left || pCurNodel->right)
				nMaxDepth++;

			if (pCurNodel->right)
				m_stackIteration.push(pCurNodel->right);

			if (pCurNodel->left)
				m_stackIteration.push(pCurNodel->left);
		}
		return nMaxDepth;*/
		int nRetValue =  TraverseTree(root, 1);
		return nRetValue;
	}
	int TraverseTree(TreeNode* pParent, int nCurDepth) {
		if (!pParent)
			return nCurDepth;

		cout << pParent->val << endl;
		int nLeftDepth = TraverseTree(pParent->left, nCurDepth);
		int nRightDepath = TraverseTree(pParent->right, nCurDepth);
		int nRetDepth = nLeftDepth >= nRightDepath ? nLeftDepth: nRightDepath;
		if (pParent->left || pParent->right)
			++nRetDepth;

		return  nRetDepth;
	}
	bool testSolution() {
		TreeNode* pNode1 = new TreeNode(3);
		TreeNode* pNode2 = new TreeNode(9);
		TreeNode* pNode3 = new TreeNode(20);
		TreeNode* pNode4 = new TreeNode(15);
		TreeNode* pNode5 = new TreeNode(7);

		pNode1->left = pNode2;
		pNode1->right = pNode3;
		pNode3->left = pNode4;
		pNode3->right = pNode5;
		int nRetValue = maxDepth(pNode1);

		TreeNode* pNode11 = new TreeNode(1);
		TreeNode* pNode22 = new TreeNode(2);
		TreeNode* pNode33 = new TreeNode(3);
		TreeNode* pNode44 = new TreeNode(4);
		TreeNode* pNode55 = new TreeNode(5);
		pNode11->left = pNode22;
		pNode11->right = pNode33;
		pNode22->left = pNode44;
		pNode33->right = pNode55;
		int nRetValue1 = maxDepth(pNode11);
		return true;
	}
protected:
	std::stack<TreeNode*>	m_stackIteration;
};

/*

class Solution {
public int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}
		else {
			int left_height = maxDepth(root.left);
			int right_height = maxDepth(root.right);
			return java.lang.Math.max(left_height, right_height) + 1;
		}
	}
}
作者：LeetCode
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/solution/er-cha-shu-de-zui-da-shen-du-by-leetcode/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
