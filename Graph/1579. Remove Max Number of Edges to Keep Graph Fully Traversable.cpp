// solution
/*
    從type 3開始連接, alice, bob都要union去做, 每次成功union
   node都要++used_edges, 如果已經union(root_x == root_y) 就不會用這條edge,
   最後total_edge - used_edge就是我們要的答案
*/
class UnionFind {
  public:
	vector<int> parent;
	vector<int> rank;
	int component;
	UnionFind(int value) {
		this->parent.resize(value + 1);
		this->rank.resize(value + 1);
		for (int i = 1; i <= value; ++i) {
			this->parent[i] = i;
			this->rank[i] = 0;
		}
		this->component = value;
	}
	int Find(int x) {
		// find root
		if (parent[x] != x)
			parent[x] = Find(parent[x]);
		return parent[x];
	}
	bool Union(int x, int y) {
		int root_x = Find(x);
		int root_y = Find(y);

		// same root, fail union
		if (root_x == root_y)
			return false;

		// merge into another tree
		if (rank[root_x] > rank[root_y]) {
			parent[root_y] = root_x;

		} else if (rank[root_x] < rank[root_y]) {
			parent[root_x] = root_y;

		} else {
			parent[root_y] = root_x;
			++rank[root_x];
		}
		--component;
		return true; // successful union
	}
};
class Solution {
  public:
	int maxNumEdgesToRemove(int n, vector<vector<int>> &edges) {
		UnionFind alice(n);
		UnionFind bob(n);
		int used_edges = 0;
		sort(edges.begin(), edges.end(),
		     [](auto &v1, auto &v2) { return v1[0] > v2[0]; });
		for (auto &e : edges) {
			if (e[0] == 3) {
				bool alice_union = alice.Union(e[1], e[2]);
				bool bob_union = bob.Union(e[1], e[2]);
				if (alice_union || bob_union)
					++used_edges;
			}
			// bob
			else if (e[0] == 2) {
				if (bob.Union(e[1], e[2]))
					++used_edges;
			} else {
				if (alice.Union(e[1], e[2]))
					++used_edges;
			}
		}
		if (alice.component > 1 || bob.component > 1)
			return -1;
		return edges.size() - used_edges;
	}
};