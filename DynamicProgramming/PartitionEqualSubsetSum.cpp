/*
1. recursive 解法
    a. 每次去分別計算subset加入nums[i]跟不加入nums[i] 的結果
    b. 如果 sum(subsets) > target == sum / 2, 代表這個subset找不到結果return回來
2. DP table儲存（Before doing recursive work, we check if we already know the
answer.） 2-D table去儲存 table[i][target] = true/false, i為目前index,
target為這個subset的target number
*/
// time complxity 可以從table 得知, 原本要看每個subset的結果O(2^n),
// 可以直接縮減到O(n*t)
class Solution {
  public:
	bool canPartition(vector<int> &nums) {
		int sum = cal_sum(nums);
		if (sum % 2 != 0)
			return false;
		int target = sum / 2;
		vector<vector<bool>> table(nums.size(),
		                           vector<bool>(target + 1, false));

		return recursive(table, nums, 0, target);
	}

  private:
	int cal_sum(vector<int> &nums) {
		int sum = 0;
		for (int &num : nums)
			sum += num;
		return sum;
	}
	bool recursive(vector<vector<bool>> &table, vector<int> &nums, int i,
	               int target) {
		// terminate condiction
		if (i == nums.size()) {
			return target == 0;
		}
		if (target < 0) {
			return false;
		}

		if (table[i][target]) {
			return table[i][target];
		}
		table[i][target] = recursive(table, nums, i + 1, target - nums[i]) ||
		                   recursive(table, nums, i + 1, target);
		return table[i][target];
	}
};
