// hint
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/*
    1. 回想BT的概念就能迎刃而解
*/
class Solution {
  public:
	TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
		return dfs(root, p, q);
	}

  private:
	TreeNode *dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
		// p, q must be left
		if (p->val < root->val && q->val < root->val) {
			return dfs(root->left, p, q);
		}
		// p, q must be right
		else if (p->val > root->val && q->val > root->val) {
			return dfs(root->right, p, q);
		} else {
			return root;
		}
	}
};
