// proficient
// 14 minute
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
/*1. BFS search
2. 額外定義一個array去記錄目前level的node數量
3. we countdown the level node when we pop out the queue value,
   we the level node == 0, then the current is our right most side node
*/
// class Solution {
//   public:
// 	vector<int> rightSideView(TreeNode *root) {
// 		vector<int> res;
// 		if (root == nullptr)
// 			return res;
// 		vector<int> level_cnt(2, 0);
// 		queue<TreeNode *> node_queue;
// 		node_queue.push(root);
// 		int l = 0;
// 		level_cnt[l] = 1;
// 		while (!node_queue.empty()) {
// 			TreeNode *node = node_queue.front();

// 			if (node->left != nullptr) {
// 				node_queue.push(node->left);
// 				++level_cnt[l + 1];
// 			}
// 			if (node->right != nullptr) {
// 				node_queue.push(node->right);
// 				++level_cnt[l + 1];
// 			}

// 			// increment next level ndoes

// 			node_queue.pop();
// 			--level_cnt[l];
// 			if (level_cnt[l] == 0) {
// 				res.push_back(node->val);
// 				++l;
// 				level_cnt.push_back(0);
// 			}
// 		}
// 		return res;
// 	}
// };

/* Solution 2
1. Same as one BFS
2. but we just count every level nodes in for loop to save another array space
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
	vector<int> rightSideView(TreeNode *root) {
		vector<int> res;
		if (root == nullptr)
			return res;
		queue<TreeNode *> node_queue;

		node_queue.push(root);
		while (!node_queue.empty()) {
			/* code */

			int curr_level_nodes = node_queue.size();

			for (int i = 0; i < curr_level_nodes; ++i) {
				TreeNode *node = node_queue.front();
				if (node->left != nullptr)
					node_queue.push(node->left);
				if (node->right != nullptr)
					node_queue.push(node->right);

				if (i == curr_level_nodes - 1) {
					// right side ndoe
					TreeNode *target = node_queue.front();
					res.push_back(target->val);
				}
				node_queue.pop();
			}
		}
		return res;
	}
};