// proficient
/*
    1. hashset 去判斷是否重複

*/
class Solution {
  public:
	bool isValidSudoku(vector<vector<char>> &board) {
		int n = board.size();
		int m = board[0].size();
		// row check
		for (int i = 0; i < n; ++i) {
			int members = 0;
			unordered_set<int> num_check;
			for (int j = 0; j < m; ++j) {
				if (board[i][j] == '.')
					continue;
				if (num_check.count(board[i][j] - '0') > 0)
					return false;
				else
					num_check.insert(board[i][j] - '0');
			}
			if (members > 0)
				return false;
		}
		cout << " row clear" << endl;
		// col check
		for (int i = 0; i < n; ++i) {
			unordered_set<int> num_check;
			for (int j = 0; j < m; ++j) {
				if (board[j][i] == '.')
					continue;
				if (num_check.count(board[j][i] - '0') > 0)
					return false;
				else
					num_check.insert(board[j][i] - '0');
			}
		}
		cout << "clear" << endl;
		// block check
		// (0,0), (0,3), (0,6)
		//
		for (int k = 0; k < n; k += 3) {
			for (int p = 0; p < m; p += 3) {

				int row = k;
				int col = p;
				unordered_set<int> num_check;
				for (int i = 0; i < 3; ++i) {
					for (int j = 0; j < 3; ++j) {
						if (board[row + i][col + j] == '.')
							continue;
						if (num_check.count(board[row + i][col + j] - '0') > 0)
							return false;
						else
							num_check.insert(board[row + i][col + j] - '0');
					}
				}
			}
		}
		return true;
	}
};