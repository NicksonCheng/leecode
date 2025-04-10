// hint
/*
    邏輯正確, coding思路錯誤, 如果用visit 0,1,2去標記DFS跑可能會走到無限loop
    Sol 1: DFS/BFS, 1. 從border出發一定是safe, 那遇到的O都要標記成S,
                    2. 整個DFS/BFS跑完之後, 再將不是'S'的'O'變成'X'
*/
class Solution {
  public:
	void solve(vector<vector<char>> &board) {
		int rows = board.size();
		int cols = board[0].size();
		vector<vector<int>> table(rows, vector<int>(cols, 0));
		queue<pair<int, int>> bfs_q;

		for (int i = 0; i < rows; ++i) {
			if (board[i][0] == 'O')
				bfs_q.push({i, 0});
			if (board[i][cols - 1] == 'O')
				bfs_q.push({i, cols - 1});
		}
		for (int i = 0; i < cols; ++i) {
			if (board[0][i] == 'O')
				bfs_q.push({0, i});
			if (board[rows - 1][i] == 'O')
				bfs_q.push({rows - 1, i});
		}
		while (!bfs_q.empty()) {
			pair<int, int> cell = bfs_q.front();
			int row = cell.first;
			int col = cell.second;
			board[row][col] = 'S';
			vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

			for (auto &dir : dirs) {
				int next_r = row + dir[0];
				int next_c = col + dir[1];
				if (next_r > 0 && next_c > 0 && next_r < rows - 1 &&
				    next_c < cols - 1 && board[next_r][next_c] == 'O')
					bfs_q.push({next_r, next_c});
			}
			bfs_q.pop();
		}
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (board[i][j] == 'O')
					board[i][j] = 'X';
				else if (board[i][j] == 'S')
					board[i][j] = 'O';
			}
		}
	}
	bool dfs(vector<vector<char>> &board, vector<vector<int>> &memo, int row,
	         int col) {}
};
