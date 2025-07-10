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
    BFS, 每個相同level 都去hashtable<TreeNode * (parent), val>
    然後不同parent assign 不同same cousins value(total_level_sum -
   same_parent_sum)
*/
#include <iostream>
using namespace std;
class Solution {
  public:
	TreeNode *replaceValueInTree(TreeNode *root) {
		unordered_map<TreeNode *, int> sibling; // {parent, sum}
		vector<pair<TreeNode *, TreeNode *>> cur_level;
		queue<pair<TreeNode *, TreeNode *>> q; // {node, parent}
		q.push({root, nullptr});

		while (!q.empty()) {
			int size = q.size();
			int total_level_sum = 0;
			sibling.clear();
			cur_level.clear();

			for (int i = 0; i < size; ++i) {
				auto [node, parent] = q.front();
				q.pop();
				// push next level node
				if (node->left)
					q.push({node->left, node});
				if (node->right)
					q.push({node->right, node});

				// calculate same parent value
				if (parent == nullptr) {
					node->val = 0;
					continue;
				}
				cur_level.push_back({node, parent});
				sibling[parent] += node->val;
				total_level_sum += node->val;
			}
			cout << total_level_sum << endl;
			for (auto &cur : cur_level) {
				auto [node, parent] = cur;
				node->val = total_level_sum - sibling[parent];
			}
		}
		return root;
	}
};