// proficient
/*
    先row reverse, 再row col 對調
*/
class Solution {
  public:
	void rotate(vector<vector<int>> &matrix) {
		// reverse row element
		int row = matrix.size();
		int col = matrix[0].size();
		for (int i = 0; i < row / 2; ++i) {
			for (int j = 0; j < col; ++j) {
				swap(matrix[i][j], matrix[row - i - 1][j]);
			}
		}

		// switch row/col
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i == j)
					break;
				swap(matrix[i][j], matrix[j][i]);
			}
		}
	}
};
