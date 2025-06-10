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
    直接traverse所有node 用heap就好
*/
class Solution {
  public:
	priority_queue<int, vector<int>, greater<>> min_heap;
	unordered_set<int> visit;
	int findSecondMinimumValue(TreeNode *root) {
		dfs(root);
		if (min_heap.size() >= 2) {
			min_heap.pop();
			return min_heap.top();
		} else
			return -1;
	}
	void dfs(TreeNode *node) {
		if (visit.count(node->val) == 0) {
			min_heap.push(node->val);
			visit.insert(node->val);
		}

		if (!node->left || !node->right)
			return;
		dfs(node->right);
		dfs(node->left);
	}
};