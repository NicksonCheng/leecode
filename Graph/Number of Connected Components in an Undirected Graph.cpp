/*
    1. Union Find
    2. DFS
*/
class Solution {
  public:
	int countComponents(int n, vector<vector<int>> &edges) {
		int components = 0;
		vector<vector<int>> graph(n);
		unordered_set<int> topology;
		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}

		for (int i = 0; i < n; ++i) {
			if (topology.find(i) != topology.end())
				continue;
			dfs(graph, topology, i);
			// there exist node not visit before this traverse
			++components;
		}
		return components;
	}
	void dfs(vector<vector<int>> &g, unordered_set<int> &t, int node) {
		if (t.find(node) != t.end())
			return;
		t.insert(node);
		for (int i = 0; i < g[node].size(); ++i) {
			int nei = g[node][i];
			dfs(g, t, nei);
		}
	}
};
