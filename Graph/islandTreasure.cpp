#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

/*
    1. 從寶藏出發跑BFS
    2. 因為每個寶藏都會同步跑一次BFS,所以被visit(不再是INT_MAX)
   就不會push進queue
*/
class Solution {
  public:
	void islandsAndTreasure(vector<vector<int>> &grid) {
		int rows = grid.size();
		int cols = grid[0].size();
		queue<pair<int, int>> treasure;

		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 0)
					treasure.push({i, j});
			}
		}

		vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		while (!treasure.empty()) {
			pair<int, int> t = treasure.front();
			int row = t.first;
			int col = t.second;
			for (int i = 0; i < 4; ++i) {
				int next_row = row + dirs[i][0];
				int next_col = col + dirs[i][1];
				// border or has been visit
				if (next_row < 0 || next_col < 0 || next_row >= rows ||
				    next_col >= cols || grid[next_row][next_col] <= 0 ||
				    grid[next_row][next_col] != INT_MAX)
					continue;
				grid[next_row][next_col] = grid[row][col] + 1;
				treasure.push({next_row, next_col});
			}
			treasure.pop();
		}
	}
};
