// proficient
// 1863. Sum of All Subset XOR Totals
/*
    1. backtracking subset, 每次subset做完都return subset total xor的值
*/
class Solution {
  public:
	int subsetXORSum(vector<int> &nums) {
		int total = recursive(nums, 0, 0);
		return total;
	}
	int recursive(vector<int> &nums, int curr_xor, int i) {

		if (i == nums.size()) {
			return curr_xor;
		}
		return recursive(nums, curr_xor, i + 1) +
		       recursive(nums, curr_xor ^ nums[i], i + 1);
	}
};