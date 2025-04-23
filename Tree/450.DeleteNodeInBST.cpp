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
/*1. remove後將右子樹拉上去, 左子樹接在右子樹最左邊
  2. 如果right subtree null, 直接接left subtree
*/
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
	TreeNode *deleteNode(TreeNode *root, int key) {
		if (root == nullptr)
			return nullptr;
		if (root->val > key) {
			// go left
			root->left = deleteNode(root->left, key);
		} else if (root->val < key) {
			// go right;
			root->right = deleteNode(root->right, key);
		} else {
			if (root->right == nullptr) {
				return root->left;
			} else {
				attachLeftSubtree(root->left, root->right);
				return root->right;
			}
		}
		return root;
	}
	void attachLeftSubtree(TreeNode *left_root, TreeNode *right_node) {
		if (right_node->left == nullptr) {
			right_node->left = left_root;
			return;
		}
		attachLeftSubtree(left_root, right_node->left);
	}
};