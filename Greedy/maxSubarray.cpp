/*
    1. 如果目前的加總 < 0, 代表這個subarray會是負數, 必須再往下找下一個subarray
*/
class Solution {
  public:
	int maxSubArray(vector<int> &nums) {
		if (nums.empty())
			return 0;
		int subarr_max_val = nums[0];
		int curr_sum = 0;
		for (int num : nums) {
			if (curr_sum < 0) {
				curr_sum = 0;
			}
			curr_sum += num;

			subarr_max_val = max(subarr_max_val, curr_sum);
		}
		return subarr_max_val;
	}
};
