/*
    不能用shortest path, 因為可能最短路徑是 > k stop,導致某些 < k 的被skip
    1. 有可能某條花費低的路徑，在達到 dst 時超過了 k stop
    2. 反而某些花費略高但 stop 較少的路徑，可以在限制內達到 dst

    sol. (因為是k stop)用單純的BFS 走 k + 1 step,
   然後回傳可以抵達dst的最小money, 如果cur_money > 最小money, 這條路徑就沒用了

*/
#include <iostream>
using namespace std;
#define Tuple tuple<int, int, int> // {money, node, stop}
#define Pair pair<int, int>
class Solution {
  public:
	int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst,
	                      int k) {
		vector<vector<Pair>> graph(n);
		vector<int> dist(n, INT_MAX);
		// create graph
		for (auto &f : flights)
			graph[f[0]].push_back({f[1], f[2]});
		queue<Pair> q;
		q.push({src, 0});
		int step = 0;
		while (!q.empty() && step <= k + 1) {
			int size = q.size();
			for (int i = 0; i < size; ++i) {
				auto [node, money] = q.front();
				q.pop();
				if (money > dist[node])
					continue;
				else
					dist[node] = money;
				// push neighbor to queue
				for (auto &nei : graph[node]) {

					q.push({nei.first, money + nei.second});
				}
			}
			++step;
		}
		return dist[dst] == INT_MAX ? -1 : dist[dst];
	}
};