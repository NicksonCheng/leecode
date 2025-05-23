// proficient
// 38 minute
/*
    題目要求, 計算每個距離1 ~ n 的pair數量
    1. 每個node 都去BFS 然後存進 vector<int> k 裡面,
        time O(V (V+E))
*/
class Solution {
  public:
	vector<int> countOfPairs(int n, int x, int y) {
		vector<int> p(n + 1, 0);

		vector<vector<int>> graph(n + 1);
		queue<int> bq;

		for (int i = 1; i < n; ++i) {
			graph[i].push_back(i + 1);
			graph[i + 1].push_back(i);
		}
		// another edge
		if (abs(x - y) > 1) {
			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		// every node calculate distance
		for (int i = 1; i <= n; ++i) {
			bq.push(i);
			int distance = 0;
			vector<bool> visit(n + 1, false); // avoid run cycle
			while (!bq.empty()) {
				int size = bq.size();
				// cout << size << " " << distance << endl;
				if (distance > 0)
					p[distance] += size;
				++distance;
				for (int j = 0; j < size; ++j) {
					int house = bq.front();
					bq.pop();
					visit[house] = true;
					// push neighbor into queue
					// cout << house << ": ";
					for (int &nei : graph[house]) {
						if (!visit[nei]) {
							// cout << nei << " ";
							bq.push(nei);
							visit[nei] = true;
						}
					}
					// cout << endl;
					//  push this pair into correspond distance
				}
			}
			// break;
		}
		p.erase(p.begin());
		return p;
	}
};