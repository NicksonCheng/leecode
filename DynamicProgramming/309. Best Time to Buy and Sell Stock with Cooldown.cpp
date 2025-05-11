/*



    dp[i][status]
    注意: 應該是回傳目前的profit 而不是將profit當作參數往下傳

    同一狀態下，會覆蓋掉其他路徑的計算結果。
    最後回傳的 profit 不一定是最大值。

*/
class Solution {
  public:
	int maxProfit(vector<int> &prices) {
		vector<vector<int>> dp(prices.size(), vector<int>(3, -1));

		return recur(prices, dp, 0, 0);
	}
	int recur(vector<int> &prices, vector<vector<int>> &dp, int i, int status) {
		if (i == prices.size())
			return 0;
		if (dp[i][status] != -1)
			return dp[i][status];
		int max_profit = 0;
		if (status == 2)
			// cooldown
			max_profit = recur(prices, dp, i + 1, 0);
		else if (status == 1) {
			// hold stock , can not buy

			// do nothing or sell
			max_profit = max(recur(prices, dp, i + 1, 1),
			                 recur(prices, dp, i + 1, 2) + prices[i]);
		} else {
			// no holding stock

			// do nothing or buy stock
			max_profit = max(recur(prices, dp, i + 1, 0),
			                 recur(prices, dp, i + 1, 1) - prices[i]);
		}
		dp[i][status] = max_profit;
		return dp[i][status];
	}
};