// proficient
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
    不斷dfs, 每次deleted 都return true給parent,當parent left,right node 都return
   true時, parent也應該被remove
*/
class Solution {
  public:
	TreeNode *removeLeafNodes(TreeNode *root, int target) {
		bool remove_root = dfs(root, target);
		if (remove_root)
			return nullptr;
		else
			return root;
	}
	bool dfs(TreeNode *node, int target) {
		if (node == nullptr)
			return true;

		bool remove_left = dfs(node->left, target);
		bool remove_right = dfs(node->right, target);
		if (remove_left) {
			node->left = nullptr;
		}
		if (remove_right)
			node->right = nullptr;
		if (remove_left && remove_right && node->val == target)
			return true;
		else
			return false;
	}
};