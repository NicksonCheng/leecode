/*
    Normal transaction買入一定要在最低點
    short selling transaction 賣出一定要在最高點
    sliding windows
    每次看目前 buy/sell的 跟 prices[i] 比較
    1.
    prices[i] > sell, 這個更值得short selling 的賣出
    prices[i] < buy, 這個更值得normal transaction 的買入

    2.
    prices[i] < sell, 計算profit
    prices[i] > buy, 計算profit

    看哪個比較大決定要用normal 還是 short selling


        sol 2. 每次prices[i]決定要 1.buy 還是2.sell, 但根據上一個step 決定,
        如果i-1是 1.buy, 那只能1,2 sell, or ignore
        如果i-1是 2.sell, 那只能1.2 buy or ignore
        如果i-1是 其他那可以1.but 2.sell, or ignore


        dp[i][state] 表示 目前這個state這max profit

        state_1: 0: sell, 1: buy
        state_2: 0: buy, 1: sell
*/
#include <iostream>
using namespace std;
class Solution {
  public:
	long long maximumProfit(vector<int> &prices, int k) {
		int n = prices.size();
		const long long NEG_INF = -1e15;
		vector<vector<vector<long long>>> dp(
		    n + 1,
		    vector<vector<long long>>(k + 1, vector<long long>(3, NEG_INF)));

		dp[0][k][0] = 0;

		for (int i = 0; i < n; ++i) {
			for (int rem_k = 0; rem_k <= k; ++rem_k) {
				for (int state = 0; state < 3; ++state) {
					long long val = dp[i][rem_k][state];
					if (val == NEG_INF)
						continue;

					// Skip
					dp[i + 1][rem_k][state] = max(dp[i + 1][rem_k][state], val);

					if (state == 0 && rem_k > 0) {
						dp[i + 1][rem_k][1] =
						    max(dp[i + 1][rem_k][1], val - prices[i]); // Buy
						dp[i + 1][rem_k][2] =
						    max(dp[i + 1][rem_k][2], val + prices[i]); // Short
					} else if (state == 1 && rem_k >= 1) {
						dp[i + 1][rem_k - 1][0] = max(dp[i + 1][rem_k - 1][0],
						                              val + prices[i]); // Sell
					} else if (state == 2 && rem_k >= 1) {
						dp[i + 1][rem_k - 1][0] =
						    max(dp[i + 1][rem_k - 1][0],
						        val - prices[i]); // Buy back
					}
				}
			}
		}

		long long ans = 0;
		for (int rem_k = 0; rem_k <= k; ++rem_k) {
			ans = max(ans, dp[n][rem_k][0]);
		}

		return ans;
	}
};
©leetcode