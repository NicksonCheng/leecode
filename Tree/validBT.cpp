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
	bool isValidBST(TreeNode *root) { return dfs(root, INT_MIN, INT_MAX); }
	bool dfs(TreeNode *node, int curr_min, int curr_max) {
		bool left_valid = true;
		bool right_valid = true;
		if (node->val <= curr_min || node->val >= curr_max)
			return false;

		if (node->left != nullptr)
			left_valid = dfs(node->left, curr_min, node->val);
		if (node->right != nullptr)
			right_valid = dfs(node->right, node->val, curr_max);
		return left_valid && right_valid;
	}
};
