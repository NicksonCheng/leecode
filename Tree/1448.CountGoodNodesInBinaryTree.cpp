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
    1. 每次都check這個node 是否比left/right大,
        parent > left/right 代表left/right not good, pass down parent->val
        parent < left/right 代表left/right good, pass down left/right-val
    2. time complexity O(n)
       space O(1)
*/
class Solution {
  public:
	int goodNodes(TreeNode *root) {
		int good_cnt = dfs(root, -101);
		return good_cnt;
	}
	int dfs(TreeNode *node, int cur_max) {
		int good = 0;
		if (node->val >= cur_max) {
			good = 1;
			cur_max = node->val;
		}

		if (node->left == nullptr && node->right == nullptr)
			return good;
		if (node->left != nullptr) {
			good += dfs(node->left, cur_max);
		}
		if (node->right != nullptr)
			good += dfs(node->right, cur_max);

		return good;
	}
};
