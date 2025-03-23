class Solution {
  public:
	int numIslands(vector<vector<char>> &grid) {
		int cnt_island = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == '1') {
					++cnt_island;
					dfs(grid, i, j);
				}
			}
		}
		return cnt_island;
	}

  private:
	void dfs(vector<vector<char>> &grid, int row, int col) {

		if (row < 0 || row >= grid.size() || col < 0 || col >= grid[row].size())
			return;

		if (grid[row][col] == '0')
			return;
		grid[row][col] = '0';
		dfs(grid, row + 1, col);
		dfs(grid, row - 1, col);
		dfs(grid, row, col + 1);
		dfs(grid, row, col - 1);
	}
};
