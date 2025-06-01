/*
    BFS, Dijkstra's algorthm, 問題在於top left -> bottom right 的shortest path
    heap 存目前最短的path, 2-D distance紀錄大家起始都是INT_MAX, greedy
   每次取最小的距離去update, 然後將下一個node distance push 到heap
*/
class Solution {
  public:
	int swimInWater(vector<vector<int>> &grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>> distance(n, vector<int>(m, INT_MAX));
		vector<vector<bool>> visit(n, vector<bool>(m, false));
		vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
		               greater<>>
		    min_heap;
		distance[0][0] = grid[0][0]; // 起點也要等
		visit[0][0] = true;
		min_heap.push({distance[0][0], 0, 0});
		while (!min_heap.empty()) {
			auto [d, r, c] = min_heap.top();
			min_heap.pop();
			// cout << d << " " << r << " " << c << " " << grid[r][c] << endl;
			if (distance[r][c] < d)
				continue; // 已經有更小的了
			for (auto &dir : dirs) {
				int next_r = r + dir[0];
				int next_c = c + dir[1];
				if (next_r >= 0 && next_r < n && next_c >= 0 && next_c < m) {

					int cur_dis = max(
					    distance[r][c],
					    grid[next_r][next_c]); // 如果cur_dis
					                           // 就已經比grid[next_r][next_c]
					                           // 大就無需等待
					if (!visit[next_r][next_c] &&
					    cur_dis < distance[next_r][next_c]) {
						// cout << cur_dis << endl;
						distance[next_r][next_c] = cur_dis;
						min_heap.push(
						    {distance[next_r][next_c], next_r, next_c});
						visit[next_r][next_c] = true;
					}
				}
			}
		}
		return distance[n - 1][m - 1];
	}
};