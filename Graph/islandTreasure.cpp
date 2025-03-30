/*
    從treasure出發BFS
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
	void islandsAndTreasure(vector<vector<int>> &grid) {
		queue<pair<int, int>> treasures;
		int m = grid.size();
		int n = grid[0].size();
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 0) {
					treasures.push({i, j});
				}
			}
		}
		visit.resize(m, vector<bool>(n, false));
		while (!treasures.empty()) {
			for (auto &row : visit) {
				fill(row.begin(), row.end(), false);
			}
			pair<int, int> t = treasures.front();
			bfs(grid, t.first, t.second, 0);
			treasures.pop();
		}
	}

  private:
	vector<vector<bool>> visit;
	void bfs(vector<vector<int>> &grid, int i, int j, int step) {
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) {
			return;
		}
		if (grid[i][j] == -1)
			return;

		if (grid[i][j] > 0) {
			grid[i][j] = min(grid[i][j], step);
		}
		if (visit[i][j])
			return;
		visit[i][j] = true;
		bfs(grid, i + 1, j, step + 1);
		bfs(grid, i - 1, j, step + 1);
		bfs(grid, i, j + 1, step + 1);
		bfs(grid, i, j - 1, step + 1);
	}
};
int main() {
	vector<vector<int>> map = {{2147483647, 2147483647, 2147483647},
	                           {2147483647, -1, 2147483647},
	                           {0, 2147483647, 2147483647}};
	Solution sol;
	sol.islandsAndTreasure(map);
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j) {
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}
