
/*
 1. 從 i 自己偷就去看i-2偷了多少然後加自己
 2. 如果 i自己偷的比 i-1還要少, 那乾脆偷i－1的 所以money[i] = money[i-1]
*/
class Solution {
  public:
	int rob(vector<int> &nums) {
		int n = nums.size();
		vector<int> money(n + 1, -1);
		money[0] = nums[0];
		money[1] = max(nums[0], nums[1]);

		for (int i = 2; i < n; ++i) {
			money[i] = max(money[i - 1], nums[i] + money[i - 2]);
		}
		return money[n - 1];
	}
};

/* Top Down*/
class Solution {
  public:
	vector<int> dp;
	int rob(vector<int> &nums) {
		int n = nums.size();
		dp.resize(n, -1);
		return dfs(nums, 0);
	}
	int dfs(vector<int> &nums, int i) {
		if (i >= nums.size())
			return 0;
		if (dp[i] != -1)
			return dp[i];
		dp[i] = max(nums[i] + dfs(nums, i + 2), dfs(nums, i + 1));
		return dp[i];
	}
};