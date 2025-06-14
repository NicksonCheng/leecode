/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
/*
    DFS 會有問題, 如果後面的node 會連回前面的node就會產生重複的new_node

    正確做法在於DFS的同時用hashmap 維護已經存在的node

    hashmap<old_Node, new_Node>
*/
class Solution {
  public:
	unordered_map<Node *, Node *> node_map;
	Node *cloneGraph(Node *node) { return dfs(node); }
	Node *dfs(Node *node) {
		if (!node)
			return nullptr;
		if (node_map.count(node) == 0) {
			Node *new_node = new Node(node->val);
			node_map[node] = new_node;
			for (int i = 0; i < node->neighbors.size(); ++i) {
				new_node->neighbors.push_back(dfs(node->neighbors[i]));
			}
			return new_node;
		} else
			return node_map[node];
	}
};