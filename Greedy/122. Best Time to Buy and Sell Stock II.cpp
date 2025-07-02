/*
    greedy, 每次hold nums[i], 看到num[j] 比較大就賣掉, 然後買入num[j],
   nums[j]比較小就改買num[j]

    dp[i][sell/buy] 表示在i-day sell/buy的max profit

    return max(dp[0][buy], dp[0][sell])
*/
class Solution {
  public:
	int maxProfit(vector<int> &prices) {
		int profit = 0;
		int hold = prices[0];
		for (int i = 1; i < prices.size(); ++i) {
			if (prices[i] > hold) {
				profit += prices[i] - hold;
			}
			hold = prices[i];
		}
		return profit;
	}
};
/*

    dp[i][sell/buy] 表示在i-day sell/buy的max profit

    return max(dp[0][buy], dp[0][sell])
*/
class Solution {
  public:
	vector<vector<int>> dp;
	int maxProfit(vector<int> &prices) {
		int n = prices.size();
		dp.resize(n, vector<int>(2, -1)); // [i-day][buy/sell]
		return max(dfs(prices, 0, 0), -prices[0] + dfs(prices, 0, 1));
	}
	int dfs(vector<int> &prices, int i, int hold_stock) {
		if (i == prices.size())
			return 0;
		if (dp[i][hold_stock] != -1)
			return dp[i][hold_stock];
		// skip
		int skip_profit = dfs(prices, i + 1, hold_stock);
		int used_profit;

		if (hold_stock == 0) {
			// buy
			used_profit = -prices[i] + dfs(prices, i + 1, 1);
			dp[i][0] = max(used_profit, skip_profit);
			return dp[i][0];
		} else {
			// sell
			used_profit = prices[i] + dfs(prices, i + 1, 0);
			dp[i][1] = max(used_profit, skip_profit);
			return dp[i][1];
		}
	}
};