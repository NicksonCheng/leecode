// solution
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
    preorder: root->left->right
    inorder:  left->root->right
    觀察: preorder是每個subtree root的所在地, 並且遵循root->left->right
         inorder 可以藉由root去分出左右兩邊subtree array index

    先用hash talbe存大家的index, 然後從從preorder[0] == root 去找 inorder
   root的位置 array 左/右邊為left/right subtree

    dfs 去建立left/right subtree

*/
class Solution {
  public:
	unordered_map<int, int> node_index;
	int pre_idx = 0;
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		for (int i = 0; i < inorder.size(); ++i)
			node_index[inorder[i]] = i;

		return dfs(preorder, 0, inorder.size() - 1);
	}
	// dfs build tree;
	TreeNode *dfs(vector<int> &preorder, int left, int right) {
		// overflow tree
		if (left > right)
			return nullptr;
		int root_val = preorder[pre_idx++];
		TreeNode *root = new TreeNode(root_val);
		int root_inorder_idx = node_index[root_val];
		// left subtree create
		root->left = dfs(preorder, left, root_inorder_idx - 1);
		// right subtree create
		root->right = dfs(preorder, root_inorder_idx + 1, right);

		return root;
	}
};
