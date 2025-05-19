/*
    1. Union Find, 如果union return false(already union), 代表這條edge是多餘的
   O(V+E)
    2. DFS, create graph的同時去dfs看看有沒有cycle, 如果有代表這條edge是多餘的
   O(E(V+E))

   3.
*/
class Solution {
  public:
	vector<int> findRedundantConnection(vector<vector<int>> &edges) {
		int n = edges.size() + 1;
		vector<vector<int>> g(n);
		for (auto &e : edges) {
			vector<bool> visit(n, false); // detect cycle
			g[e[0]].push_back(e[1]);
			g[e[1]].push_back(e[0]);

			if (detectCycle(g, visit, e[0], -1))
				return e;
		}
		return {};
	}
	bool detectCycle(vector<vector<int>> &g, vector<bool> &visit, int node,
	                 int parent) {
		if (visit[node])
			return true; // has cycle

		visit[node] = true;
		for (int i = 0; i < g[node].size(); ++i) {
			int nei = g[node][i];
			if (nei == parent)
				continue;
			if (detectCycle(g, visit, nei, node))
				return true;
		}
		return false;
	}
};
class UnionFind {
  public:
	vector<int> parent;
	vector<int> rank;
	UnionFind(int n) {
		for (int i = 0; i < n; ++i)
			parent.push_back(i);
		rank.resize(n, 1);
	};
	int Find(int x) {
		if (parent[x] != x) {
			parent[x] = Find(parent[x]);
		}
		return parent[x];
	};
	bool Union(int x, int y) {
		int root_x = Find(x);
		int root_y = Find(y);

		if (root_x == root_y)
			return false; // already union
		if (rank[root_x] > rank[root_y]) {
			parent[root_y] = root_x;
		} else if (rank[root_x] < rank[root_y])
			parent[root_x] = root_y;
		else {
			parent[root_y] = root_x;
			++rank[root_x];
		}
		return true;
	};
};
class Solution {
  public:
	vector<int> findRedundantConnection(vector<vector<int>> &edges) {
		int n = edges.size();
		UnionFind uf(n + 1);
		vector<vector<int>> g(n);
		for (auto &e : edges) {
			if (!uf.Union(e[0], e[1]))
				return e;
		}
		return {};
	}
};