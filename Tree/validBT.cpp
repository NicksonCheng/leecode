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
	bool isValidBST(TreeNode *root) { return dfs(root, LONG_MIN, LONG_MAX); }
	bool dfs(TreeNode *root, long lower, long upper) {
		if (root == nullptr)
			return true;

		// overflow
		if (root->val <= lower || root->val >= upper)
			return false;

		bool l_valid = true, r_valid = true;
		if (root->left)
			l_valid = dfs(root->left, lower, root->val);
		if (root->right)
			r_valid = dfs(root->right, root->val, upper);
		return l_valid && r_valid;
	}
};