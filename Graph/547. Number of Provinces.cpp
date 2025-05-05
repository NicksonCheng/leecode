// proficient
/*
    DFS 先建立graph, unordered_set紀錄是否走過, 不停dfs直到所有node都visit
   **********
*/
class Solution {
  public:
	int findCircleNum(vector<vector<int>> &isConnected) {
		// create graph
		int num_node = isConnected.size();
		vector<vector<int>> graph(isConnected.size());
		unordered_set<int> visit;
		for (int i = 0; i < isConnected.size(); ++i) {
			for (int j = 0; j < isConnected[i].size(); ++j) {
				if (i != j && isConnected[i][j] == 1)
					graph[i].push_back(j);
			}
		}
		int num_provinces = 0;
		// dfs untils all node visit, if there exist nodes not visit, there must
		// be extra provinces + 1
		while (visit.size() != num_node) {
			for (int i = 0; i < num_node; ++i) {
				// not visit
				if (visit.find(i) == visit.end()) {
					dfs(graph, visit, i);
					break;
				}
			}

			++num_provinces;
		}
		return num_provinces;
	}
	void dfs(vector<vector<int>> &graph, unordered_set<int> &visit, int node) {
		if (visit.find(node) != visit.end())
			return;
		visit.insert(node);
		for (int i = 0; i < graph[node].size(); ++i) {
			int nei = graph[node][i];
			dfs(graph, visit, nei);
		}
	}
};
/*
    Union-Find Solution
*/
class UnionFind {
  public:
	vector<int> parent;
	vector<int> rank;
	UnionFind() {}
	UnionFind(int n) {
		for (int i = 0; i < n; ++i) {
			parent.push_back(i);
		}
		rank.resize(n, 0);
	}
	int Find(int x) {
		if (parent[x] != x) {
			parent[x] = Find(parent[x]);
		}
		return parent[x];
	}
	void Union(int x, int y) {
		int root_x = Find(x);
		int root_y = Find(y);
		// already union
		if (root_x == root_y)
			return;

		// small tree hang on large tree
		if (rank[root_x] > rank[root_y])
			parent[root_y] = root_x;
		else if (rank[root_y] > rank[root_x])
			parent[root_x] = root_y;
		else {
			// same rank, hang root_y to root_x, and rank_x++
			parent[root_y] = root_x;
			++rank[root_x];
		}
	}
};
class Solution {
  public:
	int findCircleNum(vector<vector<int>> &isConnected) {
		int n = isConnected.size();
		UnionFind *uf = new UnionFind(n);
		for (int node = 0; node < n; ++node) {
			for (int i = 0; i < isConnected[node].size(); ++i) {
				if (node != i && isConnected[node][i] == 1) {
					uf->Union(node, i);
				}
			}
		}
		// # parent in union is # of provinces
		// 注意: 最後必須要conpress確保parent是一致的
		unordered_set<int> provinces;
		for (int &p : uf->parent)
			provinces.insert(uf->Find(p));
		return provinces.size();
	}
};
