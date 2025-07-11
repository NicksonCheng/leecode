/*
    Binary Search + DFS

    先假設 minimum cost = m 的時候是否能符合# compoennt <= k(DFS), binary search
   找到minimum cost
*/
class Solution {
  public:
	int minCost(int n, vector<vector<int>> &edges, int k) {
		if (edges.empty())
			return 0;
		sort(edges.begin(), edges.end(),
		     [](auto &e1, auto &e2) { return e1[2] < e2[2]; });
		int l = 0;
		int r = edges.back()[2];
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (numComponents(n, m, edges) <= k)
				r = m - 1;
			else
				l = m + 1;
		}
		return l;
	}
	int numComponents(int n, int min_cost, vector<vector<int>> &edges) {
		vector<vector<int>> graph(n);
		vector<bool> visit(n, false);
		for (auto &e : edges) {
			if (e[2] <= min_cost) {
				graph[e[0]].push_back(e[1]);
				graph[e[1]].push_back(e[0]);
			}
		}
		int num_comps = 0;
		for (int i = 0; i < visit.size(); ++i) {
			if (!visit[i]) {
				dfs(graph, visit, i);
				++num_comps;
			}
		}
		return num_comps;
	}
	void dfs(vector<vector<int>> &graph, vector<bool> &visit, int i) {
		visit[i] = true;
		for (int &nei : graph[i]) {
			if (!visit[nei])
				dfs(graph, visit, nei);
		}
	}
};
©leetcode