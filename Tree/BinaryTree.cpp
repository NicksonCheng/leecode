#include <iostream>
#include <vector>
using namespace std;

typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
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
	void printTree(TreeNode *root, string traversal) {

		// Preorder Traversal: root->left->right
		if (traversal == "preorder") {

			if (root == nullptr) {
				return;
			}
			cout << root->val << " ";
			printTree(root->left, traversal);
			printTree(root->right, traversal);
		}
		// Inorder Traversal: left->root->right
		else if (traversal == "inorder") {
			if (root == nullptr) {
				return;
			}

			printTree(root->left, traversal);
			cout << root->val << " ";
			printTree(root->right, traversal);

		}
		// Postorder Traversal: left->right->root
		else if (traversal == "postorder") {
			if (root == nullptr) {
				return;
			}
			printTree(root->left, traversal);
			printTree(root->right, traversal);
			cout << root->val << " ";
		}
	}
};

int main() {
	Solution sol;
	vector<int> arr = {13, 4, 18, 8, 2};

	// Create and print initial tree
	TreeNode *root = sol.createBinaryTree(arr);
	sol.printTree(root, "preorder");
	cout << endl;
	sol.printTree(root, "inorder");
	cout << endl;
	sol.printTree(root, "postorder");
	cout << endl;
	exit(1);
	// Insert a new node
	// cout << "Inserting 4: ";
	// sol.insertNode(root, 4);
	// sol.printTree(root);
	// cout << endl;

	// // Delete a node
	// cout << "Deleting 6: ";
	// root = sol.deleteNode(root, 6);
	// sol.printTree(root);
	// cout << endl;

	// Clean up memory (optional)
	// Add tree deletion logic here if needed

	return 0;
}