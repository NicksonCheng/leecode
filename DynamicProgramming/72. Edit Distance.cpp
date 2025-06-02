// solution
/*
    char相同不計算operation, i1, i2 都+1
    每次有3種選擇
    change-> i1 + 1, i2 + 1, operation + 1
    insert-> i2 + 1, oepration + 1
    delete-> i1 + 1, operation + 1

    i1 先到end-> insert n2 - i2 + 1;
    i2 先到end -> delete n1 - i1 + 1;

    O(3^(m + n))

    DP: dp[i1][i2] 紀錄目前index下的mini operation

*/
class Solution {
  public:
	int n1, n2;
	vector<vector<int>> dp;
	int minDistance(string word1, string word2) {
		n1 = word1.length();
		n2 = word2.length();
		dp.resize(n1, vector<int>(n2, -1));
		return dfs(word1, word2, 0, 0);
	}
	int dfs(string &word1, string &word2, int i1, int i2) {
		if (i1 >= n1 && i2 >= n2)
			return 0;
		else if (i1 >= n1)
			return n2 - i2;
		else if (i2 >= n2)
			return n1 - i1;
		if (dp[i1][i2] >= 0)
			return dp[i1][i2];
		if (word1[i1] == word2[i2]) {
			dp[i1][i2] = dfs(word1, word2, i1 + 1, i2 + 1);
			return dp[i1][i2];
		}
		return dp[i1][i2] =
		           1 + min({
		                   dfs(word1, word2, i1 + 1, i2 + 1), // replace
		                   dfs(word1, word2, i1, i2 + 1),     // insert
		                   dfs(word1, word2, i1 + 1, i2)      // delete
		               });
	}
};
