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
	bool isSameTree(TreeNode *p, TreeNode *q) {
		diveTree(p, q);
		return same;
	}

  private:
	bool same = true;
	void diveTree(TreeNode *p, TreeNode *q) {
		if (p != nullptr && q != nullptr) {
			if (p->val != q->val)
				same = false;
			diveTree(p->left, q->left);
			diveTree(p->right, q->right);
			return;
		}
		if (p == nullptr && q == nullptr)
			return;

		// only one null
		same = false;
		return;
	}
};
