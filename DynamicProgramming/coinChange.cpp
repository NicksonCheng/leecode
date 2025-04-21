

/*
    time compexity 很高, DP可能性極高
    1. 建立table, table 為0~amount 需要change的最小次數
    2. 目標為table[amount]的值
    3. 我們可以從table[0] bottom-up 上來, 因為table[0]就是0
*/
class Solution {
  public:
	int coinChange(vector<int> &coins, int amount) {
		vector<int> table(amount + 1, amount + 1);
		table[0] = 0;
		for (int i = 0; i <= amount; ++i) {
			for (int j = 0; j < coins.size(); ++j) {
				// coin[j] > i 代表這個coin行不通, <= i 代表還可以繼續扣
				if (coins[j] <= i) {
					int amount_idx = i - coins[j];

					// 去看 i -coins[j] (上一個coin step) 有沒有路走
					table[i] = min(table[i], 1 + table[amount_idx]);
				}
			}
		}
		return table[amount] == amount + 1 ? -1 : table[amount];
	}
};

/* Top Down*/
class Solution {
  public:
	int coinChange(vector<int> &coins, int amount) {
		vector<int> table(amount + 1, -1);
		int count = recursive(coins, table, amount);
		return count == INT_MAX ? -1 : count;
	}
	int recursive(vector<int> &coins, vector<int> &table, int amount) {
		if (amount == 0)
			return 0;
		if (amount < 0 || table[amount] == INT_MAX)
			return INT_MAX; // 此路不通

		if (table[amount] > 0)
			return table[amount];

		int min_count = INT_MAX;
		for (int i = 0; i < coins.size(); ++i) {
			min_count =
			    min(min_count, recursive(coins, table, amount - coins[i]));
		}
		table[amount] = min_count == INT_MAX ? INT_MAX : min_count + 1;
		return table[amount];
	}
};