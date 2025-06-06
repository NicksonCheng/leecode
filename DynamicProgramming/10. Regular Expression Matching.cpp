// solutions
/*
    s,p two pointer

    每次看s[i], p[j]是否match
    p[j + 1] = '*', 則決定ignore(j + 2), 或是繼續用當前(preceding) char

    n = s.length, m = p.length

    time O(2^(m + n))

    2. dp[i][j] 代表在目前s[i], p[j] 下是否達成regular expression matching
*/
class Solution {
  public:
	vector<vector<int>> dp;

	bool isMatch(string s, string p) {
		dp.resize(s.length() + 1, vector<int>(p.length() + 1, -1));
		return recursive(s, p, 0, 0);
	}

	bool recursive(string &s, string &p, int i, int j) {
		if (dp[i][j] != -1)
			return dp[i][j];

		// 如果 pattern 用完，檢查 s 是否也用完
		if (j == p.length())
			return dp[i][j] = (i == s.length());

		// 檢查 s[i] 和 p[j] 是否匹配（前提是 i 還沒超出範圍）
		bool match = (i < s.length() && (s[i] == p[j] || p[j] == '.'));

		// 檢查下個 pattern 字元是否是 *
		if (j + 1 < p.length() && p[j + 1] == '*') {
			// 忽略這段 pattern（相當於 * 出現0次） or 繼續匹配當前字元
			dp[i][j] = (recursive(s, p, i, j + 2) ||
			            (match && recursive(s, p, i + 1, j)));
		} else {
			// 正常下一步匹配
			dp[i][j] = match && recursive(s, p, i + 1, j + 1);
		}

		return dp[i][j];
	}
};
