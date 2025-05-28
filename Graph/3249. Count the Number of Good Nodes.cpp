/*
    DFS, 計算child subtree看是否相同計算good node,
    time O(V + E)

    space O(V + E)
*/
class Solution {
  public:
	int good_nodes = 0;
	int countGoodNodes(vector<vector<int>> &edges) {
		int n = edges.size();
		// create graph
		vector<vector<int>> graph(n + 1);
		vector<bool> visit(n + 1, false);
		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}
		int dummy = dfs(graph, visit, 0);
		return good_nodes;
	}
	int dfs(vector<vector<int>> &graph, vector<bool> &visit, int node) {
		int count = 0;
		int same = -1;
		bool is_good = true;
		visit[node] = true;
		for (int &nei : graph[node]) {
			if (visit[nei])
				continue;
			int child_count = dfs(graph, visit, nei);
			if (same == -1)
				same = child_count;
			else if (same != child_count)
				is_good = false;
			count += child_count;
		}
		if (is_good)
			++good_nodes;
		return count + 1;
	}
};