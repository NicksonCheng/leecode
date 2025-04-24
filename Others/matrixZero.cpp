/*
    1. 我們直接拿首行首列作為儲存標記(這一row, 這一col是否全為0)
*/
class Solution {
  public:
	void setZeroes(vector<vector<int>> &matrix) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		bool firstRowZero = false;
		bool firstColZero = false;

		// 檢查首行是否有0
		for (int j = 0; j < cols; ++j) {
			if (matrix[0][j] == 0) {
				firstRowZero = true;
				break;
			}
		}

		// 檢查首列是否有0
		for (int i = 0; i < rows; ++i) {
			if (matrix[i][0] == 0) {
				firstColZero = true;
				break;
			}
		}

		// 標記需要置零的行和列
		for (int i = 1; i < rows; ++i) {
			for (int j = 1; j < cols; ++j) {
				if (matrix[i][j] == 0) {
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}

		// 置零（忽略首行首列）
		for (int i = 1; i < rows; ++i) {
			if (matrix[i][0] == 0) {
				for (int j = 1; j < cols; ++j) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = 1; j < cols; ++j) {
			if (matrix[0][j] == 0) {
				for (int i = 1; i < rows; ++i) {
					matrix[i][j] = 0;
				}
			}
		}

		// 根據標記置零首行
		if (firstRowZero) {
			for (int j = 0; j < cols; ++j) {
				matrix[0][j] = 0;
			}
		}

		// 根據標記置零首列
		if (firstColZero) {
			for (int i = 0; i < rows; ++i) {
				matrix[i][0] = 0;
			}
		}
	}
};
