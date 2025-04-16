/*
    先去找首字母的cell, 然後dfs找string,有找到直接return true;
    time complexity 為 O(m * 4^n) 因為上下左右都會去看
*/
/*
    檢討: 1. backtrasking visit map要注意
          2. DFS visit_map檢查要注意是下一個row, col
*/
class Solution {
  public:
	bool exist(vector<vector<char>> &board, string word) {
		bool is_exist = false;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] == word[0]) {
					set<pair<int, int>> visit_map;
					is_exist = dfs(board, visit_map, i, j, 0, word);
				}
				if (is_exist)
					return is_exist;
			}
		}
		return is_exist;
	}
	bool dfs(vector<vector<char>> &board, set<pair<int, int>> &visit_map,
	         int row, int col, int i, string target_word) {
		// exceed border or mismatch word

		if (row < 0 || col < 0 || row >= board.size() ||
		    col >= board[0].size() || board[row][col] != target_word[i])
			return false;

		visit_map.insert({row, col});
		if (i == target_word.length() - 1)
			return true;

		vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		for (auto &dir : dirs) {
			if (visit_map.find({row + dir[0], col + dir[1]}) != visit_map.end())
				continue;
			if (dfs(board, visit_map, row + dir[0], col + dir[1], i + 1,
			        target_word))
				return true;
		}
		visit_map.erase({row, col}); // backtrasking
		return false;
	}
};
