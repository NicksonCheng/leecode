/*
    heap 額外儲存目前狀態(下一步是1 or 2)
*/
class Solution {
  public:
	int minTimeToReach(vector<vector<int>> &moveTime) {

		// row and columns
		int n = moveTime.size();
		int m = moveTime[0].size();

		// {distance, {row,col, status}}
		priority_queue<pair<int, vector<int>>, vector<pair<int, vector<int>>>,
		               greater<>>
		    min_heap;
		// next move directions
		vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		// current minimal times
		vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
		// start form {0,0}
		distances[0][0] = 0;
		min_heap.push({0, {0, 0, 1}});

		while (!min_heap.empty()) {
			int cur_dir = min_heap.top().first;
			vector<int> node = min_heap.top().second;
			int i = node[0], j = node[1], step = node[2];
			min_heap.pop();

			// outdated times(we find minial distance before)
			if (cur_dir > distances[i][j])
				continue;

			// move from 4 adj directions
			for (auto &d : dirs) {
				int next_i = i + d[0];
				int next_j = j + d[1];
				if (next_i < 0 || next_i >= n || next_j < 0 || next_j >= m)
					continue;

				int path = max(cur_dir, moveTime[next_i][next_j]) + step;
				if (path < distances[next_i][next_j]) {
					distances[next_i][next_j] = path;

					// push current node to mini_heap
					int next_step = step == 1 ? 2 : 1;
					min_heap.push({path, {next_i, next_j, next_step}});
				}
			}
		}
		return distances[n - 1][m - 1];
	}
};