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
    root->left->right
    1. recursive
    2. stack, 先push right 再push left
*/
class Solution {
  public:
	vector<int> preorderTraversal(TreeNode *root) {
		stack<TreeNode *> s;
		s.push(root);
		vector<int> res;
		while (!s.empty()) {
			TreeNode *node = s.top();
			s.pop();
			if (node == nullptr)
				continue;
			res.push_back(node->val);
			s.push(node->right);
			s.push(node->left);
		}
		return res;
	}
};