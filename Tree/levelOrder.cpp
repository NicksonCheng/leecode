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
    1. BFS research
    2. utilized Queue to finish it
    3. time complexity O(n)
*/
class Solution {
  public:
	vector<vector<int>> levelOrder(TreeNode *root) {
		// used quue to implement BFS
		vector<vector<int>> res;
		queue<TreeNode *> q;
		q.push(root);
		int curr_h = 0;
		while (!q.empty()) {
			vector<int> level;
			int size = q.size(); // current level nodes
			for (int i = 0; i < size; ++i) {
				TreeNode *curr_node = q.front();
				q.pop();
				if (curr_node) {
					level.push_back(curr_node->val);
					q.push(curr_node->left);
					q.push(curr_node->right);
				}
			}
			if (!level.empty())
				res.push_back(level);
		}
		return res;
	}
};
