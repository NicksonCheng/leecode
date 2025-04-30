// proficient
/*
    DFS, 無法走的方向preimeter+1
    19 分鐘
*/
class Solution {
  public:
	vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
	vector<vector<bool>> visit;
	int islandPerimeter(vector<vector<int>> &grid) {
		// find start island pointer
		int rows = grid.size();
		int cols = grid[0].size();
		visit.resize(rows, vector<bool>(cols, false));
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == 1) {
					return dfs(grid, i, j);
				}
			}
		}
		return 0;
	}
	int dfs(vector<vector<int>> &grid, int row, int col) {
		// if encounter the boundary or water, return 1(one part of island)
		if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
		    grid[row][col] == 0)
			return 1;
		if (visit[row][col])
			return 0;
		visit[row][col] = true;
		int perimeter = 0;

		// dfs from 4 directions
		for (auto &dir : dirs) {
			perimeter += dfs(grid, row + dir[0], col + dir[1]);
		}

		return perimeter;
	}
};