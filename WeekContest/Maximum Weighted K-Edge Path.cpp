
/* DFS, 原本每個node都跑一遍會TLE,
   想像一種狀況, current node 用相同path數量(selected_edge) 跟 相同weight 到達,
   但是不同path, 這樣就會重複計算到

   dp[node][num_edges][weight]

      (0)
     /   \
    1     2
     \   /
       3

   */
class Solution {
  public:
	int k, t;
	int max_path = -1;

	int maxWeight(int n, vector<vector<int>> &edges, int k, int t) {
		this->k = k;
		this->t = t;

		vector<vector<pair<int, int>>> graph(n);
		for (auto &e : edges) {
			graph[e[0]].emplace_back(e[1], e[2]);
		}

		// dp[node][selected_edge] = set of weights we've visited
		vector<vector<unordered_set<int>>> dp(
		    n, vector<unordered_set<int>>(k + 1));

		for (int i = 0; i < n; ++i) {
			dfs(graph, dp, i, 0, 0);
		}

		return max_path;
	}

	void dfs(const vector<vector<pair<int, int>>> &graph,
	         vector<vector<unordered_set<int>>> &dp, int node, int cur_weight,
	         int select_edge) {

		if (cur_weight >= t)
			return;

		if (select_edge == k) {
			max_path = max(max_path, cur_weight);
			return;
		}

		// 若這個狀態已經走過
		if (dp[node][select_edge].count(cur_weight))
			return;
		dp[node][select_edge].insert(cur_weight);

		for (auto &[nei, w] : graph[node]) {
			dfs(graph, dp, nei, cur_weight + w, select_edge + 1);
		}
	}
};
©leetcode
    /* BFS 作法*/
    class Solution {
  public:
	int maxWeight(int n, vector<vector<int>> &edges, int k, int t) {
		vector<vector<pair<int, int>>> graph(n);
		for (auto &e : edges) {
			graph[e[0]].emplace_back(e[1], e[2]);
		}

		int max_path = -1;

		// visited[node][steps] = set of weights we've seen at (node, steps)
		vector<vector<unordered_set<int>>> visited(
		    n, vector<unordered_set<int>>(k + 1));

		queue<tuple<int, int, int>> q; // (node, weight, steps)

		for (int i = 0; i < n; ++i) {
			q.emplace(i, 0, 0);
			visited[i][0].insert(0);
		}

		while (!q.empty()) {
			auto [node, weight, steps] = q.front();
			q.pop();

			if (weight >= t)
				continue;
			if (steps == k) {
				max_path = max(max_path, weight);
				continue;
			}

			for (auto &[nei, w] : graph[node]) {
				int new_weight = weight + w;
				int new_steps = steps + 1;

				if (new_weight >= t)
					continue;
				if (visited[nei][new_steps].count(new_weight))
					continue;

				visited[nei][new_steps].insert(new_weight);
				q.emplace(nei, new_weight, new_steps);
			}
		}

		return max_path;
	}
};
©leetcode