// solution
// 超時

/*
    dfs, 每個node都走一遍紀錄color, time O(V * (V + E))

    正解: kahn's algorithm + DP
    kahn's algorithm, 從indegree 0 的node出發,
   每個node都紀錄每個color最大出現次數 最後在end的地方找出最大color



*/
#include <iostream>
using namespace std;
class Solution {
  public:
	int largestPathValue(string colors, vector<vector<int>> &edges) {
		int n = colors.length();
		vector<vector<int>> graph(n);
		vector<int> indegree(n, 0); // {indegree, prefix color}
		vector<vector<int>> dp(
		    n,
		    vector<int>(
		        26, 0)); // dp[node][color]代表走到該node每個color出現的最大次數
		queue<int> q;
		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			++indegree[e[1]];
		}
		// find indegree = 0 node
		for (int i = 0; i < indegree.size(); ++i) {
			if (indegree[i] == 0)
				q.push(i);
		}
		int largest_color = 0;
		int deleted_nodes = 0; // detect cycle
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			++deleted_nodes;
			// add self to the path
			++dp[node][colors[node] - 'a'];
			// at the end of path, we calculate most frequent color
			if (graph[node].size() == 0) {
				for (int i = 0; i < 26; ++i)
					largest_color = max(largest_color, dp[node][i]);
			}
			for (int &nei : graph[node]) {
				// update neighbor indegree and add color path to it
				--indegree[nei];

				// find max color in every path
				for (int i = 0; i < 26; ++i) {
					dp[nei][i] = max(dp[node][i], dp[nei][i]);
				}

				// if indegree become 0, add to queue
				if (indegree[nei] == 0)
					q.push(nei);
			}
		}
		return deleted_nodes == n ? largest_color : -1;
	}
};