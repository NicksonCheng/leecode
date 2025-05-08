/*
    修正: 四個方向都要走才對而不是右下
*/
class Solution {
  public:
	int minTimeToReach(vector<vector<int>> &moveTime) {
		int n = moveTime.size();
		int m = moveTime[0].size();
		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
		               greater<>>
		    min_heap;
		vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
		distances[0][0] = 0;
		min_heap.push({0, {0, 0}});

		while (!min_heap.empty()) {
			int cur_dis = min_heap.top().first;
			vector<int> node = min_heap.top().second;
			min_heap.pop();
			if (cur_dis > distances[node[0]][node[1]])
				continue;
			for (auto &d : dirs) {
				int next_i = node[0] + d[0];
				int next_j = node[1] + d[1];
				if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
					continue;

				// 不能比moveTime[next_i][next_j] 早到, 提早到就要在那邊等
				int path = max(cur_dis, moveTime[next_i][next_j]) + 1;

				// greedy find shortest path
				if (path < distances[next_i][next_j]) {
					distances[next_i][next_j] = path;
					min_heap.push({path, {next_i, next_j}});
				}
			}
		}
		return distances[n - 1][m - 1];
	}
};