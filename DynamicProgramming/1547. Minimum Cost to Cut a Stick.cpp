// solution
/*
    1. recursive cuts, 每個順序都試試看
       O(n!)
    2. DP[i][j] 代表 [i, j] 區間的cut minimum cost,
       dp[i][j] = min(dp[i][k] + dp[k][j]) + (j - i)

    1,3,4,5, n = 7

    [ 不能切 ] -> [ 可以切一刀 ] -> [ 可以切兩刀 ] -> ...
    cuts = [1,3,4,5]
    不能切, [0,1], [1,3], [3,4], [4,5]
    切一刀, [0,3], [1, 4], [3,5], [4, 7]
    切兩刀: [0,4], [3, 7]
    每次都是上一次的minimum

    transaction function
    k = [i + 1 ~ j - 1]
    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cost)

*/
class Solution {
  public:
	int minCost(int n, vector<int> &cuts) {
		cuts.push_back(0);
		cuts.push_back(n);
		sort(cuts.begin(), cuts.end());
		int m = cuts.size();
		vector<vector<int>> dp(
		    m, vector<int>(m, 0)); // 只需要紀錄interval 之間的dp就好

		// 從切一刀(len = 2)的開始跑
		for (int len = 2; len < m; ++len) {
			for (int i = 0; i + len < m; ++i) {
				int j = i + len;
				dp[i][j] = INT_MAX;
				// [i + 1 ~ j - 1]
				for (int k = i + 1; k < j; ++k) {
					dp[i][j] = min(dp[i][j],
					               dp[i][k] + dp[k][j] + (cuts[j] - cuts[i]));
				}
			}
		}
		return dp[0][m - 1];
	}
};