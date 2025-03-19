
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
	int maxDepth(TreeNode *root) {
		if (root == nullptr)
			return 0;

		return 1 + max(maxDepth(root->left), maxDepth(root->right));
	}
};
int main() {
	Solution sol;
	vector<int> arr = {1, 2, 3, 4};
	TreeNode *root = sol.createBinaryTree(arr);
	cout << sol.maxDepth(root) << endl;
	;
	return 0;
}
