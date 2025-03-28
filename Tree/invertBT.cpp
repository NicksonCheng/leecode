
#include <iostream>
#include <vector>
using namespace std;
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {};
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
} TreeNode;

class Solution {
  public:
	TreeNode *createBinaryTree(vector<int> arr) {
		TreeNode *root = nullptr;
		for (int i = 0; i < arr.size(); ++i) {
			root = insertNode(root, arr[i]);
		}
		return root;
	}
	TreeNode *insertNode(TreeNode *root, int val) {
		if (root == nullptr) {
			TreeNode *node = (TreeNode *)new TreeNode(val);
			return node;
		}
		if (val < root->val) {
			root->left = insertNode(root->left, val);
		} else {
			root->right = insertNode(root->right, val);
		}
		return root;
	}
	TreeNode *invertTree(TreeNode *root) {
		if (root == nullptr)
			return root;
		TreeNode *tmp = root->left;
		root->left = root->right;
		root->right = tmp;
		invertTree(root->left);
		invertTree(root->right);
		return root;
	}
};
int main() {
	Solution sol;
	vector<int> arr = {4, 2, 7, 1, 3, 6, 9};
	TreeNode *root = sol.createBinaryTree(arr);
	root = sol.invertTree(root);
	return 0;
}
