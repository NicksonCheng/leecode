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
    postorder: root->left->right
    inorder: left->root->right, 得知tree分布左右關係
    postorder: left->right->root, 最後一個是root

    sol.1: 先建立inorder的index hashtable, 再透過postorder 去dfs(right first)
   build tree
*/
class Solution {
  public:
	unordered_map<int, int> table;
	int post_idx;
	TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
		// create inorder index table
		int n = inorder.size();
		post_idx = n - 1;
		for (int i = 0; i < n; ++i) {
			table[inorder[i]] = i;
		}

		//
		return dfs(postorder, inorder, 0, n - 1);
	}
	TreeNode *dfs(vector<int> &postorder, vector<int> &inorder, int l, int r) {
		if (l > r)
			return nullptr;                   // overflow the leaf
		int node_val = postorder[post_idx--]; // current root node value
		int inorder_idx =
		    table[node_val]; // find this root node index in inorder

		TreeNode *root = new TreeNode(node_val);

		// create left/right subtree(right first)
		root->right = dfs(postorder, inorder, inorder_idx + 1, r);
		root->left = dfs(postorder, inorder, l, inorder_idx - 1);

		return root;
	}
};