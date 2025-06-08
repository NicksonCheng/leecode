#include <iostream>
using namespace std;

/*
    每次check 目前subarray 是否符合max - min <= k條件
    符合就兩種選擇
    1. 繼續expand
    2. split, start new subarray

    不符合就return
*/
class Solution {
  public:
	int modolo = 1e9 + 7;
	vector<int> dp;
	int countPartitions(vector<int> &nums, int k) {
		dp.resize(nums.size(), -1);
		dfs(nums, 0, k, INT_MIN, INT_MAX);
		return num_comb;
	}
	int dfs(vector<int> &nums, int i, int k, int max_val, int min_val) {
		if (i == nums.size()) {
			return 1;
		}
		if (dp[i] != -1)
			return dp[i];
		max_val = max(max_val, nums[i]);
		min_val = min(min_val, nums[i]);
		long long num_comb;
		if (max_val - min_val <= k) {
			// expand or split
			num_comb = (dfs(nums, i + 1, k, max_val, min_val) +
			            dfs(nums, i + 1, k, INT_MIN, INT_MAX)) %
			           modolo;

		} else
			num_comb = 0;
		dp[i] = num_comb;
		return dp[i];
	}
};