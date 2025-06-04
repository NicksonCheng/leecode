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
    DFS, 每次check root 是否為Binary Search Tree, 並且計算left subtree+ right
   subtree + root->val 的sum 如果current root 是BST, 就更新maximum Sum

    問題: [1,null,10,-5,20] 這個測資會有問題, 因為無法保證right_subtree mini val
   > root->val 修正: structure紀錄每個subtree 的maxLeft, minRight, 從left node
   紀錄上來
*/
typedef struct Nodedata {
	bool isBST;
	int sum;
	int maxLeft;
	int minRight;

	Nodedata() : isBST(true), sum(0), maxLeft(INT_MIN), minRight(INT_MAX) {};
} Nodedata;
class Solution {
  public:
	int max_sum = 0;
	int maxSumBST(TreeNode *root) {
		Nodedata *root_nd = sumBST(root);
		if (root_nd->isBST)
			max_sum = max(max_sum, root_nd->sum);
		return max_sum;
	}
	Nodedata *sumBST(TreeNode *node) {
		Nodedata *cur_nd = new Nodedata();
		if (node == nullptr)
			return cur_nd;
		Nodedata *left_nd = sumBST(node->left);
		Nodedata *right_nd = sumBST(node->right);

		// not BST
		if (!left_nd->isBST || !right_nd->isBST ||
		    node->val <= left_nd->maxLeft || node->val >= right_nd->minRight) {
			// update max sum if left/right subtree is BST
			cur_nd->isBST = false;
			return cur_nd;
		}
		// BST
		cur_nd->sum = left_nd->sum + right_nd->sum + node->val;
		max_sum = max(cur_nd->sum, max_sum);
		cur_nd->maxLeft = max(node->val, right_nd->maxLeft);
		cur_nd->minRight = min(node->val, left_nd->minRight);
		return cur_nd;
	}
};