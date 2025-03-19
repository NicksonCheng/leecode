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
		if (arr.empty())
			return nullptr;

		TreeNode *root = new TreeNode(arr[0]);
		for (int i = 1; i < arr.size(); i++) {
			insertNode(root, arr[i]);
		}
		return root;
	}

	TreeNode *insertNode(TreeNode *root, int val) {
		if (root == nullptr) {
			return new TreeNode(val);
		}

		if (val < root->val) {
			root->left = insertNode(root->left, val);
		} else {
			root->right = insertNode(root->right, val);
		}
		return root;
	}

	TreeNode *deleteNode(TreeNode *root, int val) {
		if (root == nullptr)
			return nullptr;

		if (val < root->val) {
			root->left = deleteNode(root->left, val);
		} else if (val > root->val) {
			root->right = deleteNode(root->right, val);
		} else {
			// Node with only one child or no child
			if (root->left == nullptr) {
				TreeNode *temp = root->right;
				delete root;
				return temp;
			} else if (root->right == nullptr) {
				TreeNode *temp = root->left;
				delete root;
				return temp;
			}

			// Node with two children
			TreeNode *temp = findMin(root->right);
			root->val = temp->val;
			root->right = deleteNode(root->right, temp->val);
		}
		return root;
	}

	void printTree(TreeNode *root) {
		if (root == nullptr)
			return;

		printTree(root->left);
		cout << root->val << " ";
		printTree(root->right);
	}

  private:
	TreeNode *findMin(TreeNode *root) {
		while (root->left != nullptr) {
			root = root->left;
		}
		return root;
	}
};

int main() {
	Solution sol;
	vector<int> arr = {1, 3, 6, 9, 15, 2, 30, 26};

	// Create and print initial tree
	TreeNode *root = sol.createBinaryTree(arr);
	cout << "Initial tree (in-order): ";
	sol.printTree(root);
	cout << endl;

	// Insert a new node
	cout << "Inserting 4: ";
	sol.insertNode(root, 4);
	sol.printTree(root);
	cout << endl;

	// Delete a node
	cout << "Deleting 6: ";
	root = sol.deleteNode(root, 6);
	sol.printTree(root);
	cout << endl;

	// Clean up memory (optional)
	// Add tree deletion logic here if needed

	return 0;
}