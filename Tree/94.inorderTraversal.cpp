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
	vector<int> inorderTraversal(TreeNode *root) {
		// left -> root -> right
		vector<int> res;
		dfs(res, root);
		return res;
	}
	void dfs(vector<int> &res, TreeNode *node) {
		if (node == nullptr)
			return;

		dfs(res, node->left);
		res.push_back(node->val);
		dfs(res, node->right);
	}
};