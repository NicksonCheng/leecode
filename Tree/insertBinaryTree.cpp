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
 1. brutal force, 先把每個node都push進去vector, 然後再重新create tree, time
 O(n), space O(n)
 2. 直接判斷應該放在哪裡, time O(logn), space O(1)

 **陷阱: 注意root null情況不能直接return 要有值去接她因為我們是call by value
*/
class Solution {
  public:
	TreeNode *insertIntoBST(TreeNode *root, int val) {
		root = dfs(nullptr, root, val, 0);
		return root;
	}
	TreeNode *dfs(TreeNode *last_node, TreeNode *node, int val,
	              int child_type) {
		// need to connect to last node, child_type 0/left 1/right
		if (node == nullptr) {
			if (last_node == nullptr) {
				node = new TreeNode(val);
			} else {
				if (child_type == 0)
					last_node->left = new TreeNode(val);
				else
					last_node->right = new TreeNode(val);
			}
			return node;
		}
		TreeNode *dummy;
		if (val < node->val)
			dummy = dfs(node, node->left, val, 0);
		else
			dummy = dfs(node, node->right, val, 1);
		return node;
	}
};