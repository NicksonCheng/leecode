// proficient
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
    1. DFS, 每次走到leaf就跟目前的string比較, 直到找到最小, time O(N), space
   O(H) H: tree height

    2. BFS + Min Heap（優先隊列）
    使用最小堆（min-heap）維護每個 leaf 到 root 的路徑字串（記得 reverse）。
    第一個 pop 出來的 leaf string 就是答案。
    ⏱ Time Complexity:

    每個節點最多訪問一次，每個字串 reverse 為 O(H)。
    優先隊列插入最多 N 條路徑，每次操作 log N。
    總體時間複雜度：O(N log N)（比 DFS 稍慢）

*/
class Solution {
  public:
	string smallest_str = "";
	string smallestFromLeaf(TreeNode *root) {
		dfs(root, "");
		// for(int i = 0; i < smallest_str.length(); ++i)
		//     smallest_str[i] += 'a';
		return smallest_str;
	}
	void dfs(TreeNode *node, string cur_str) {
		// leaf
		if (node)
			cur_str += (node->val + 'a');
		if (!node->left && !node->right) {
			reverse(cur_str.begin(), cur_str.end()); // from end to start
			if (smallest_str.length() == 0)
				smallest_str = cur_str;

			for (int i = 0; i < cur_str.length(); ++i) {
				if (i >= smallest_str.length() || cur_str[i] > smallest_str[i])
					return; // lexicographically larger
				else if (cur_str[i] < smallest_str[i])
					break;
				else
					continue;
			}
			smallest_str = cur_str; // lexicographically smaller 或是 prefix
			return;
		}
		if (node->left)
			dfs(node->left, cur_str);
		if (node->right)
			dfs(node->right, cur_str);
	}
};

string smallestFromLeaf(TreeNode *root) {
	priority_queue<string, vector<string>, greater<string>> pq;
	queue<pair<TreeNode *, string>> q;
	q.push({root, ""});
	while (!q.empty()) {
		auto [node, cur_str] = q.front();
		q.pop();
		string path = (char)(node->val + 'a') + cur_str;
		if (!node->left && !node->right) {
			pq.push(path); // 因為是從 leaf 開始
		}
		if (node->left)
			q.push({node->left, path});
		if (node->right)
			q.push({node->right, path});
	}
	return pq.top();
}