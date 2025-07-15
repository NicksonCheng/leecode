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
 * }
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

/* iterative version*/

/*
    stack 去運作, 先不斷push left 直到 leaf, pop 的同時如果有right node
   就必須push right subtree
*/
class Solution {
  public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		stack<TreeNode *> s;
		while (root || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			if (!s.empty()) {
				TreeNode *node = s.top();
				s.pop();
				res.push_back(node->val);
				if (node->right != nullptr)
					root = node->right;
			}
		}
		return res;
	}
};