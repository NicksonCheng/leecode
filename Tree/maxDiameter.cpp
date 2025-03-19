/**
 * Brutal Force: go through every node in the tree and compute its left height
 * and right height, returning the maximum diameter found O(n^2),
 * 也就是每個subtree都要走一遍
 *
 *
 *  DFS O(n):
 *  1. max diameter = left_depth + right_depth
 *  2. must define another maxDepth function and used global max_diameter to
 * store it(considering the subtree max diameter problem)
 *
 */

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
	int diameterOfBinaryTree(TreeNode *root) {
		if (root == nullptr)
			return 0;

		maxDepth(root);
		return max_diameter;
	}

  private:
	int max_diameter = 0;
	int maxDepth(TreeNode *root) {
		if (root == nullptr)
			return 0;
		// must consider sub-tree condition
		int left_depth = maxDepth(root->left);
		int right_depth = maxDepth(root->right);
		int curr_depth = 1 + max(left_depth, right_depth);
		int curr_diameter = left_depth + right_depth;

		if (curr_diameter > max_diameter)
			max_diameter = curr_diameter;
		return curr_depth;
	}
};
