/*
    shortest path問題, w > 0, 用dijkstra's algorithm O((V+E)logV)

    n vector 紀錄每個node的shortest path, min_heap 來決定現在要走的node
    用greedy方式每次從目前path最短的node走
*/
class Solution {
  public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k) {

		vector<int> distance(n + 1, INT_MAX);
		vector<vector<pair<int, int>>> graph(n + 1); // u->{w,v}
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
		    procession;
		// create graph
		for (auto &t : times) {
			graph[t[0]].push_back({t[2], t[1]});
		}
		// push start node into heap
		procession.push({0, k});
		distance[k] = 0;
		// start calculate shortest path
		while (!procession.empty()) {
			int cur_d = procession.top().first;
			int u = procession.top().second;
			procession.pop();
			// skip outdate path
			if (cur_d > distance[u]) {

				continue;
			}
			for (auto &neis : graph[u]) {
				int w = neis.first;
				int v = neis.second;
				int path = distance[u] + w;

				// greedy(shorter path) choose next node
				if (path < distance[v]) {
					distance[v] = path;
					procession.push({distance[v], v});
				}
			}
		}

		// find last node to receive signal

		int max_distance = *max_element(distance.begin() + 1, distance.end());

		return max_distance == INT_MAX ? -1 : max_distance;
	}
};