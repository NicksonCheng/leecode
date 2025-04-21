// hint
/*
    subset + coin change組合
    1. recursive 每次拿coin看能不能==amount
    2. DP table[cur_amount] = coin_combination
    3. 陷阱: 避免重複計算combination, 2D table (curr_amount, start_idx)
*/
class Solution {
  public:
	int change(int amount, vector<int> &coins) {
		vector<vector<int>> table(amount + 1, vector<int>(coins.size(), -1));
		int total_count = recursive(coins, table, amount, 0);
		return total_count;
	}
	int recursive(vector<int> &coins, vector<vector<int>> &table, int amount,
	              int idx) {
		if (amount == 0)
			return 1;
		if (amount < 0 || table[amount][idx] == 0)
			return 0; // 無解
		if (table[amount][idx] != -1)
			return table[amount][idx];

		int total = 0;
		// 拿目前的coin
		total += recursive(coins, table, amount - coins[idx], idx);

		// 不拿目前的coin, 往下拿coin
		if (idx + 1 < coins.size())
			total += recursive(coins, table, amount, idx + 1);
		table[amount][idx] = total;
		return table[amount][idx];
	}
};
