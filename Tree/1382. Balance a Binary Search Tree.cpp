// proficient
// 24分鐘
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
    按照inorder(sorted)將node 排列好, 中間的node是new root, 再左右每次取middle
   放到left, right create new binary search tree

*/
class Solution {
  public:
	vector<int> node_list;
	TreeNode *balanceBST(TreeNode *root) {
		inorder(root);
		return createBST(0, node_list.size() - 1);
	}
	TreeNode *createBST(int l, int r) {
		if (l > r)
			return nullptr; // 防止overflow
		int m = l + (r - l) / 2;
		TreeNode *node = new TreeNode(node_list[m]);
		if (l < r) {
			node->left = createBST(l, m - 1);
			node->right = createBST(m + 1, r);
		}
		return node;
	}
	void inorder(TreeNode *node) {
		if (node == nullptr)
			return;
		inorder(node->left);
		node_list.push_back(node->val);
		inorder(node->right);
	}
};