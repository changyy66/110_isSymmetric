// 110_isSymmetric.cpp : 定义控制台应用程序的入口点。
//
/*
给定一个二叉树，检查它是否是镜像对称的。

例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

1
/ \
2   2
/ \ / \
3  4 4  3
但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

1
/ \
2   2
\   \
3    3
说明:

如果你可以运用递归和迭代两种方法解决这个问题，会很加分。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/symmetric-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include "stdafx.h"
#include <stack>

using namespace std;
/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool isSymmetricHelper(TreeNode* left, TreeNode* right)
	{
		if (left == NULL && right == NULL)return true;
		if (left == NULL || right == NULL)return false;

		if (left->val != right->val)return false;

		return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
	}

	bool isSymmetric(TreeNode* root) {
		if (!root)return true;
		return isSymmetricHelper(root->left, root->right);
	}

	bool isSymmetric1(TreeNode* root) {
		if (!root)return true;
		stack<TreeNode *> left_s;
		stack<TreeNode *> right_s;
		TreeNode *left, *right;
		left = root->left;
		right = root->right;
		while ((left&&right)||(left==NULL&&right==NULL))
		{
			if (left == NULL&&right == NULL)
			{
				if (left_s.size()==0)
				{
					return true;
				}
				left = left_s.top();
				left_s.pop();
				right = right_s.top();
				right_s.pop();
				continue;
			}
			if (left->val != right->val)return false;
			left_s.push(left->right);
			right_s.push(right->left);
			left = left->left;
			right = right->right;	
		}
		return false;	
	}
};
int main()
{
    return 0;
}

