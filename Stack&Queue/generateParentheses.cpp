class Solution {
  public:
	vector<string> generateParenthesis(int n) {
		backtracking(n, 0, 0, "");
		return res;
	}

  private:
	vector<string> res;
	void backtracking(int n, int open, int close, string curr_par) {
		if (open == n && open == close) {
			res.push_back(curr_par);
			return;
		}
		// 持續push '('
		if (open < n) {
			curr_par += '(';
			backtracking(n, open + 1, close, curr_par);

			// backtrack 回來要pop出來 表示目前這個open的數量做完了, ex: (((
			// 已結束, 換((去做
			curr_par.pop_back();
		}
		// 尚未閉合
		if (close < open) {

			curr_par += ')';
			backtracking(n, open, close + 1, curr_par);
			curr_par.pop_back();
		}
	}
};
