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
    1. 直接traverse BST, 全部丟進min_heap, 然後去kth smallest, time complexity
   O(n), space O(n)
    2. 利用BST特性DFS先找最小值, 然後每次return 都去增加count次數, 當count == k
   的時候就是kth samllest time complexity O(logn)
*/
class Solution {
  public:
	int count = 0;
	int kth_num;
	int kthSmallest(TreeNode *root, int k) {
		dfs(root, k);
		return kth_num;
	}
	void dfs(TreeNode *node, int k) {
		if (node == nullptr)
			return;

		dfs(node->left, k);
		++count;
		if (count == k) {
			kth_num = node->val;
			return;
		}
		dfs(node->right, k);
	}
};
