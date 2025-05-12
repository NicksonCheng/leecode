// solution
/*

    max_dp[i] 紀錄目前這個index的max product
    min_dp[i] 紀錄目前這個index的min product(可能與上一個負負得正變最大)


*/
class Solution {
  public:
	int maxProduct(vector<int> &nums) {
		vector<int> max_dp(nums.size(), INT_MIN);
		vector<int> min_dp(nums.size(), INT_MAX);
		max_dp[0] = nums[0];
		min_dp[0] = nums[0];
		int max_prod = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			// 連續or切斷
			int cur_max = max_dp[i - 1];
			int cur_min = min_dp[i - 1];

			max_dp[i] = max({nums[i], nums[i] * cur_max, nums[i] * cur_min});
			min_dp[i] = min({nums[i], nums[i] * cur_max, nums[i] * cur_min});

			max_prod = max(max_prod, max_dp[i]);
		}
		return max_prod;
	}
};