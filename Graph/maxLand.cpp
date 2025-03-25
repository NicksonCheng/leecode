class Solution {
  public:
	int maxAreaOfIsland(vector<vector<int>> &grid) {
		int max_area = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 0)
					continue;
				int curr_area = dfs(grid, i, j);
				if (curr_area > max_area)
					max_area = curr_area;
			}
		}
		return max_area;
	}

  private:
	int dfs(vector<vector<int>> &grid, int row, int col) {
		// exceed border or water
		if (row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() ||
		    grid[row][col] == 0)
			return 0;

		grid[row][col] = 0;
		return 1 + dfs(grid, row + 1, col) + dfs(grid, row - 1, col) +
		       dfs(grid, row, col + 1) + dfs(grid, row, col - 1);
	}
};
