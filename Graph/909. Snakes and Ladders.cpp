/*
    BFS, 每次走到有ladder,snake的地方就要跳躍, 並且計算walk, 直到終點

    visit 要確保這條路沒走過
*/
class Solution {
  public:
	int snakesAndLadders(vector<vector<int>> &board) {
		queue<int> q;
		int walk = 0;
		int n = board.size();
		int end = n * n;
		vector<bool> visit(end + 1, false);
		q.push(1);

		while (!q.empty()) {
			int size = q.size();
			++walk;
			for (int i = 0; i < size; ++i) {
				int cur_num = q.front();
				q.pop();
				// cout << cur_num << endl;
				if (cur_num + 6 >= end) {
					return walk;
				}
				for (int j = 1; j <= 6; ++j) {
					int next_num = cur_num + j;
					auto [row, col] = countPos(board, n, next_num);
					if (board[row][col] == end) {
						// cout << board[row][col] << endl;
						return walk; // 直接跳到終點
					}
					if (board[row][col] != -1) {
						if (visit[board[row][col]])
							continue;
						visit[board[row][col]] = true;
						q.push(board[row][col]);
						continue;
					}
					if (visit[next_num])
						continue;
					visit[next_num] = true;
					q.push(next_num);
				}
			}
		}
		return -1;
	}
	pair<int, int> countPos(vector<vector<int>> &board, int n, int num) {
		--num; // 0-index方便計算
		int row = n - num / n - 1;
		int col = (n - row - 1) % 2 == 0 ? num % n : n - num % n - 1;
		return {row, col};
	}
};