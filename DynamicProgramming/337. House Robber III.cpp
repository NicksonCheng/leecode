/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * rig ht(right) {}
 * };
 */
/*
    Pair 儲存 <偷, 不偷>
    current node
    steal: left/right node 不可偷, 直接回傳left/right second
    not steal: left/right node 可偷可不偷 回傳max value
*/
#define Pair pair<int, int>
class Solution {
  public:
	int rob(TreeNode *root) {
		auto [s, ns] = dfs(root);
		return max(s, ns);
	}
	Pair dfs(TreeNode *node) {
		if (node == nullptr)
			return {0, 0};
		auto [l_s, l_ns] = dfs(node->left);
		auto [r_s, r_ns] = dfs(node->right);
		// steal this node
		int s_val = node->val + l_ns + r_ns;
		// do not steal this node
		int ns_val = max(l_s, l_ns) + max(r_s, r_ns);

		return {s_val, ns_val};
	}
};