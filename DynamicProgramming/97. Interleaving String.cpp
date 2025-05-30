/*
    1. two pointer, 每次先找s3 prefix match的, 如果這個string找不到了
    就跳到另一個string移動pointer找, 反復橫跳, 直到跑完, 兩邊都找不到就是false
        time: O(n + m)

    每次recursive 看能否expand s1 substring 或是從s2找下一個substr(反之)
    dp[i][j] 代表在s1[0~i] s2[0~j] 下是符合的

    time O(n * m), space O(n * m)
*/
class Solution {
  public:
	int n;
	int m;

	vector<vector<int>> dp;
	bool isInterleave(string s1, string s2, string s3) {
		n = s1.length();
		m = s2.length();
		if (n + m != s3.length())
			return false;
		dp.resize(n + 1, vector<int>(m + 1, -1));
		return recur(s1, s2, s3, 0, 0, 0);
	}
	bool recur(string &s1, string &s2, string &s3, int i, int j, int k) {
		if (k == s3.length())
			return true;
		if (dp[i][j] != -1)
			return dp[i][j];
		bool inter_1 = false;
		bool inter_2 = false;
		if (i < n && s1[i] == s3[k])
			inter_1 = recur(s1, s2, s3, i + 1, j, k + 1);
		if (j < m && s2[j] == s3[k])
			inter_2 = recur(s1, s2, s3, i, j + 1, k + 1);
		dp[i][j] = inter_1 || inter_2;
		return dp[i][j];
	}
};