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

class Solution {
  public:
	Node *cloneGraph(Node *node) {
		Node *new_g = dfs(node);
		return new_g;
	}

  private:
	unordered_map<Node *, Node *> clone_map;
	Node *dfs(Node *g) {
		if (g == nullptr)
			return nullptr;
		Node *new_g = nullptr;
		if (clone_map.count(g) > 0) {

			// 已經create過了, 直接return 就好,
			// 讓上一層node的nei直接連到這個node
			return clone_map[g];
		} else {
			new_g = (Node *)new Node(g->val);
			clone_map[g] = new_g;
		}

		for (int i = 0; i < g->neighbors.size(); ++i) {
			new_g->neighbors.push_back(dfs(g->neighbors[i]));
		}

		return new_g;
	}
};
