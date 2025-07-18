/*
    dp[i][j]
    i == j : dp[i][j] = 2 + dp[i + 1][j - 1]
    i != j : dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
*/
class Solution {
  public:
	vector<vector<int>> dp;
	int longestPalindromeSubseq(string s) {
		int n = s.length();
		dp.resize(n, vector<int>(n, -1));
		return dfs(s, 0, n - 1);
	}
	int dfs(string &s, int i, int j) {
		if (i >= j)
			return i == j; // i == j 只有自己也是palindrome
		if (dp[i][j] != -1)
			return dp[i][j];
		if (s[i] == s[j])
			dp[i][j] = dfs(s, i + 1, j - 1) + 2;
		else
			dp[i][j] = max(dfs(s, i + 1, j), dfs(s, i, j - 1));
		return dp[i][j];
	}
};