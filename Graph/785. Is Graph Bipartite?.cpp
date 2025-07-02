/*
    目標在於找到set A, set B, 兩個set 都包含所有edge
    union find, 每次都去看node的edge 是否在union裡面, 如果是,
   代表這個node是在另一個union, 如果union超過2個就沒辦法行程bipartity graph


    DFS. 兩種set 標示從node 0 開始走, 鄰居node 標示為另一個set,
   如果可以全部走完且不會有neighbor set 同時為 0/1 代表可以形成bipartity graph
*/
/* Union Find*/
class UnionFind {
	vector<int> parent;
	vector<int> rank;
	UnionFind(int n) {
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
		}
		rank.resize(n, 0);
	}
	int Find(int node) {
		if (parent[node] != node) {
			parent[node] = Find(parent[node]);
		}
		return parent[node];
	}
	bool Union(int node_1, int node_2) {
		int root_1 = Find(node_1);
		int root_2 = Find(node_2);

		if (root_1 == root_2) {
			return false; // already union
		}
		if (rank[root_1] > rank[root_2]) {
			parent[root_2] = root_1;
		} else if (rank[root_1] < rank[root_2])
			parent[root_1] = root_2;
		else {
			parent[root_2] = root_1;
			++rank[root_1];
		}
		return true;
	}
};
#include <iostream>
using namespace std;
/*
    Union Find, 每個node neighbor都和自己屬於不同union group, 每個node check
   find(u) == find(u) return false, 然後neighbor都union 成同一個group

    DFS. 兩種set 標示從node 0 開始走, 鄰居node 標示為另一個set,
   如果可以全部走完且不會有neighbor set 同時為 0/1 代表可以形成bipartity graph
*/
class UnionFind {
  public:
	vector<int> parent;
	vector<int> rank;
	UnionFind(int n) {
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
		}
		rank.resize(n, 0);
	}
	int Find(int x) {
		// connect to other node, must a node parent is itself
		if (parent[x] != x) {
			parent[x] = Find(parent[x]);
		}
		return parent[x];
	}
	bool Union(int x, int y) {
		int root_x = Find(x);
		int root_y = Find(y);

		if (root_x == root_y)
			return false; // already union
		if (rank[root_x] > rank[root_y]) {
			parent[root_y] = parent[root_x];
		} else if (rank[root_x] < rank[root_y])
			parent[root_x] = parent[root_y];
		else {
			parent[root_y] = parent[root_x];
			++rank[root_x];
		}
		return true;
	}
};
class Solution {
  public:
	bool isBipartite(vector<vector<int>> &graph) {
		// initialized union for every node
		int n = graph.size();
		UnionFind uf(n);
		for (int node = 0; node < graph.size(); ++node) {
			// find(u) == find(v) return false(need different group from node to
			// neighbor)
			for (int &nei : graph[node]) {
				if (uf.Find(node) == uf.Find(nei))
					return false;
			}
			// Union all neighbors
			if (graph[node].empty())
				continue;
			int nei_0 = graph[node][0];
			for (int j = 1; j < graph[node].size(); ++j) {
				int nei = graph[node][j];
				uf.Union(nei_0, nei);
			}
		}
		return true;
	}
};
/* DFS */
class Solution {
  public:
	bool isBipartite(vector<vector<int>> &graph) {
		int n = graph.size();
		vector<bool> visit(n, false);
		vector<int> group_idx(n, -1);
		unordered_set<int> topology;

		for (int i = 0; i < n; ++i) {
			if (!dfs(graph, visit, group_idx, i))
				return false;
		}
		return true;
	}
	bool dfs(vector<vector<int>> &graph, vector<bool> &visit,
	         vector<int> &group_idx, int node) {

		// check if this node is legal
		int nei_idx = -1;
		for (int &nei : graph[node]) {
			if (group_idx[nei] != -1) {
				if (nei_idx == -1)
					nei_idx = group_idx[nei];
				else if (group_idx[nei] != nei_idx)
					return false; // neighbor has two different group idx, can't
					              // not be biparitiy
			}
		}
		// cout << group_idx[node] << endl;
		group_idx[node] = nei_idx == -1 ? 0 : nei_idx ^ 1; //
		visit[node] = true;
		// dfs neighbor node
		for (int &nei : graph[node]) {
			if (!visit[nei] && !dfs(graph, visit, group_idx, nei))
				return false;
		}
		return true;
	}
};