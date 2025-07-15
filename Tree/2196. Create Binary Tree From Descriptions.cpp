/*
ex1: descriptions = [[20,15,1],[20,17,0],[15,10,1]]
     output: root = 20
ex2: descriptions = [[1,2,1],[2,3,0],[3,4,1]]
     output: root = 1
*/
/*
    將所有ndoe value都紀錄在hashtable, 並且建立TreeNode connection,
   最後透過hashset找到root node return 即可
*/
class Solution {
  public:
	TreeNode *createBinaryTree(vector<vector<int>> &descriptions) {
		unordered_map<int, TreeNode *> nodes;
		unordered_set<int> children;

		for (auto &d : descriptions) {
			int parent = d[0], child = d[1], isLeft = d[2];
			// not exist in table, create new node
			if (!nodes.count(parent))
				nodes[parent] = new TreeNode(parent);
			if (!nodes.count(child))
				nodes[child] = new TreeNode(child);

			// connect the parent/child
			if (isLeft)
				nodes[parent]->left = nodes[child];
			else
				nodes[parent]->right = nodes[child];

			children.insert(child);
		}
		// find the root node(not children in any node)
		for (auto &[val, node] : nodes)
			if (!children.count(val))
				return node;

		return nullptr; // just in case
	}
};
