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

class Solution {
  public:
	bool isSubtree(TreeNode *root, TreeNode *subRoot) {
		if (root == nullptr)
			return false;
		bool same_tree = isSametree(root, subRoot);
		return same_tree || isSubtree(root->left, subRoot) ||
		       isSubtree(root->right, subRoot);
	}

  private:
	bool isSametree(TreeNode *p, TreeNode *q) {
		if (p == nullptr && q == nullptr)
			return true;
		if (p != nullptr && q != nullptr) {
			bool val_check = (p->val == q->val);
			bool l_check = isSametree(p->left, q->left);
			bool r_check = isSametree(p->right, q->right);
			return l_check && r_check && val_check;
		}
		// only one null
		return false;
	}
};
