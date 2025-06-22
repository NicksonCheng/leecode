#include <iostream>
#include <unordered_set>
using namespace std;

/*
    greedy, 每次看 subtree回傳的value, 增加比較小的那個, 如果相同則不用增加
*/
class Solution {
  public:
	vector<bool> visit;
	int increments = 0;
	int minIncrease(int n, vector<vector<int>> &edges, vector<int> &cost) {
		vector<vector<int>> graph(n);
		visit.resize(n, false);
		for (auto &e : edges) {
			graph[e[0]].push_back(e[1]);
			graph[e[1]].push_back(e[0]);
		}
		long long dummy = dfs(n, graph, cost, 0);
		return increments;
	}
	long long dfs(int n, vector<vector<int>> &graph, vector<int> &cost,
	              int root) {
		visit[root] = true;
		long long root_cost = cost[root];
		unordered_map<long long, long long> subtree_cost;
		long long max_sub_cost = 0;
		for (auto &nei : graph[root]) {
			if (visit[nei])
				continue;
			long long c = dfs(n, graph, cost, nei);
			++subtree_cost[c];
			max_sub_cost = max(max_sub_cost, c);
		}
		visit[root] = false;
		for (auto &sc : subtree_cost) {
			if (sc.first != max_sub_cost)
				increments += sc.second;
		}
		return root_cost + max_sub_cost;
	}
};