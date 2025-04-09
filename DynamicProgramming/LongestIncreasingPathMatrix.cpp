// hint
/*1. DFS 問題, 每個cell 都去走DFS回傳length最長的, 但 time
  complexity會是O((m*n)^2)

  2. DP: 透過table儲存目前用個cell的longest path,
  其他cell走過這個已儲存的cell就可以直接用

  3. 想法正確, 但超時
*/
#include <iostream>
using namespace std;

class Solution {
  public:
	int longestIncreasingPath(vector<vector<int>> &matrix) {

		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> table(rows, vector<int>(cols, 0));
		int max_length = 0;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				max_length = max(max_length, dfs(matrix, table, i, j, -1));
			}
		}
		return max_length;
	}
	int dfs(vector<vector<int>> &matrix, vector<vector<int>> &table, int row,
	        int col, int last_num) {
		if (row < 0 || col < 0 || row >= matrix.size() ||
		    col >= matrix[0].size() || matrix[row][col] <= last_num)
			return 0;
		if (table[row][col] > 0)
			return table[row][col];
		vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		int max_length = 0;
		for (auto &dir : dirs) {
			int cur_length = dfs(matrix, table, row + dir[0], col + dir[1],
			                     matrix[row][col]) +
			                 1;

			if (cur_length > max_length)
				max_length = cur_length;
		}
		table[row][col] = max_length;
		return table[row][col];
	}
};
