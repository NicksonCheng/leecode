// proficient
/*
    sol 1. brutal force, 每個subarray的總和都看一次, O(n^2)
    sol 2. sliding window, right++ 直到total > target, left++直到total < target,
     紀錄最小subarray
    每個item都只有被add/remove 一次, O(n)
*/
class Solution {
  public:
	int minSubArrayLen(int target, vector<int> &nums) {
		int l = 0;
		int total = 0;
		int min_length = INT_MAX;
		for (int r = 0; r < nums.size(); ++r) {
			total += nums[r];
			while (total - nums[l] >= target) {
				total -= nums[l++];
			}
			// record minimal subarray length
			if (total >= target)
				min_length =
				    min(min_length, r - l + 1); // (l, r) 是目前最小range
		}
		return min_length == INT_MAX ? 0 : min_length;
	}
};