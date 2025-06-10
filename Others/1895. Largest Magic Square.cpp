/*
    sol.1 brutal force, 每個k square 都跑一遍然後計算 k x k grid
   row/cols/diagonal sum是否相同, time complexity O((m * n) * k)

    0 2
    1 1
    2 0
*/
class Solution {
  public:
	int m;
	int n;
	int largestMagicSquare(vector<vector<int>> &grid) {
		m = grid.size();
		n = grid[0].size();
		int k = 2;
		int max_k = 1;
		while (k <= m && k <= n) {
			bool find = false;
			for (int i = 0; i + k <= m; ++i) {
				if (find)
					break;
				for (int j = 0; j + k <= n; ++j) {
					if (isMagic(grid, i, j, k)) {
						find = true;
						break;
					}
				}
			}
			if (find)
				max_k = k;
			++k;
		}
		return max_k;
	}
	bool isMagic(vector<vector<int>> &grid, int row, int col, int k) {
		int global_sum = -1;
		int sum;
		// check each col sum
		for (int i = col; i < col + k; ++i) {
			sum = 0;
			for (int j = row; j < row + k; ++j) {
				sum += grid[j][i];
			}
			if (global_sum == -1)
				global_sum = sum;
			else if (global_sum != sum)
				return false;
		}
		// check each row sum
		for (int i = row; i < row + k; ++i) {
			sum = 0;
			for (int j = col; j < col + k; ++j) {
				sum += grid[i][j];
			}
			if (global_sum != sum)
				return false;
		}
		// check diagonal
		sum = 0;
		for (int i = 0; i < k; ++i) {
			sum += grid[row + i][col + i];
		}

		if (sum != global_sum)
			return false;
		// check reverse diagonal
		sum = 0;
		for (int i = 0; i < k; ++i) {
			sum += grid[row + i][col + k - 1 - i];
		}
		if (sum != global_sum)
			return false;
		// correspond to the condition
		return true;
	}
};