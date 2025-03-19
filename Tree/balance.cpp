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

class Solution {
  public:
	bool isBalanced(TreeNode *root) {

		if (root == nullptr)
			return true;
		dfs(root);
		return balance;
	}

  private:
	bool balance = true;
	int dfs(TreeNode *root) {
		if (root == nullptr)
			return 0;
		int l_d = dfs(root->left);
		int r_d = dfs(root->right);
		if (abs(l_d - r_d) > 1)
			balance = false;
		return 1 + max(l_d, r_d);
	}
};
