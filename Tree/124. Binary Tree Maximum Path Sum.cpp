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
    每個node 都return以自己為subtree下最長的path, 也必須要有global
variable去紀錄max path in every subtree

    subtree path比較, 先紀錄path = node->val(因為一定會通過root), 再看left right
> 0就加入paht, return 的時候只能return 左右兩邊比較大的, 不可以一起return

time: O(n)
*/
class Solution {
  public:
	int max_path = INT_MIN;
	int maxPathSum(TreeNode *root) {
		int dummy = dfs(root);

		return max_path;
	}
	int dfs(TreeNode *node) {
		if (node == nullptr)
			return 0;

		int left_path = dfs(node->left);
		int right_path = dfs(node->right);
		int max_child = max(left_path, right_path);
		// decide max path in this subtree
		int path = node->val;
		if (left_path > 0)
			path += left_path;
		if (right_path > 0)
			path += right_path;
		max_path = max(max_path, path);

		return max_child > 0 ? node->val + max_child : node->val;
	}
};