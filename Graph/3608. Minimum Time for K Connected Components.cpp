/*
    sort the edge by time, union find from the back of time until num_comps < k

    從後面union 回來

*/
class UnionFind {
  public:
	vector<int> parent;
	vector<int> rank;
	int num_comps;
	UnionFind(int n) {
		for (int i = 0; i < n; ++i)
			parent.push_back(i);
		rank.resize(n, 0);
		num_comps = n;
	};
	int Find(int x) {
		// find root node
		if (parent[x] != x) {
			parent[x] =
			    Find(parent[x]); // decrease the tree height to accerlate search
		}
		return parent[x];
	};
	void Union(int x, int y) {
		int root_x = Find(x);
		int root_y = Find(y);
		if (root_x == root_y)
			return; // already union
		--num_comps;
		if (rank[root_x] > rank[root_y]) {
			parent[root_y] = root_x;
		} else if (rank[root_x] < rank[root_y]) {
			parent[root_x] = root_y;
		} else {
			parent[root_y] = root_x;
			++rank[x];
		}
	};
};
class Solution {
  public:
	int minTime(int n, vector<vector<int>> &edges, int k) {
		UnionFind uf(n);
		auto cmp = [](auto &e1, auto &e2) { return e1[2] > e2[2]; };
		sort(edges.begin(), edges.end(), cmp);
		int min_time = INT_MAX;
		for (int i = 0; i < edges.size(); ++i) {
			int u = edges[i][0], v = edges[i][1], time = edges[i][2];
			if (uf.num_comps < k)
				return min_time;
			uf.Union(u, v);
			min_time = min(min_time, time);
		}
		if (uf.num_comps >= k)
			min_time = 0;
		return min_time;
	}
};