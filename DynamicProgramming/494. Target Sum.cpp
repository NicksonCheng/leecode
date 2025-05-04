// hint
/*
    recursive 去算目前num[i]為正or負情況下sum(nums)是否為target

    count = sumNumbers(-num[i], i + 1) + sumNumbers(num[i], i + 1);

    talbe[i(index position)][current_sum] = count;

    ** 注意sum可能<0需要offset去轉移到1000~2000
*/
class Solution {
  public:
	int offset = 1000;
	int findTargetSumWays(vector<int> &nums, int target) {
		int n = nums.size();
		vector<vector<int>> table(n, vector<int>(2002, -1));

		return sumNumbers(nums, table, 0, 0, target);
	}
	int sumNumbers(vector<int> &nums, vector<vector<int>> &table, int i,
	               int sum, int target) {
		// sum 可能 < 0, table會runtime error, 將<0的值bias到1000~2000儲存
		if (i == nums.size()) {
			return sum == target ? 1 : 0;
		}
		int sum_idx = sum < 0 ? offset + abs(sum) : sum;

		if (table[i][sum_idx] != -1)
			return table[i][sum_idx];

		table[i][sum_idx] =
		    sumNumbers(nums, table, i + 1, sum + nums[i], target) +
		    sumNumbers(nums, table, i + 1, sum - nums[i], target);

		return table[i][sum_idx];
	}
};