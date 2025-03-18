
#include <iostream>
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
	TreeNode *createBinaryTree(vector<int> arr) {}
	TreeNode *invertTree(TreeNode *root) {}
};
int main() {}
