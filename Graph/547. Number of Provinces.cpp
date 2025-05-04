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
class Solution {
  public:
	int findCircleNum(vector<vector<int>> &isConnected) {
		int n = isConnected.size();
		vector<int> parent(n);
		iota(parent.begin(), parent.end(), 0);

		function<int(int)> find = [&](int x) {
			if (parent[x] != x)
				parent[x] = find(parent[x]);
			return parent[x];
		};

		auto unite = [&](int x, int y) {
			int px = find(x), py = find(y);
			if (px != py)
				parent[px] = py;
		};

		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (isConnected[i][j])
					unite(i, j);

		unordered_set<int> unique_provinces;
		for (int i = 0; i < n; ++i)
			unique_provinces.insert(find(i));

		return unique_provinces.size();
	}
};
