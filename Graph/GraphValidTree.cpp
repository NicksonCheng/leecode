/*
    非DAG問題,
    DFS: 從node 0開始走, 遇到visit過的node 表示有cycle

    注意: 如果有node沒有連接(有node沒visit)代表tree不成立

*/
class Solution {
  public:
	bool validTree(int n, vector<vector<int>> &edges) {
		// create graph
		vector<vector<int>> graph(n);
		vector<bool> visit(n, false);

		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}

		// detect cycle
		if (!dfs(graph, visit, 0, -1))
			return false;
		for (int i = 0; i < visit.size(); ++i) {
			if (!visit[i])
				return false;
		}
		return true;
	}
	bool dfs(vector<vector<int>> &graph, vector<bool> &visit, int node,
	         int parent) {
		// cycle
		if (visit[node])
			return false;
		// dfs neighbor node
		visit[node] = true;
		for (int i = 0; i < graph[node].size(); ++i) {
			int nei = graph[node][i];
			if (nei == parent)
				continue;
			cout << node << " " << nei << endl;
			if (!dfs(graph, visit, nei, node))
				return false;
		}
		return true;
	}
};
