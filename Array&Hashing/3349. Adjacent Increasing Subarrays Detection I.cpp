/*
    acending 直到不滿足 nums[i] > nums[i - 1], subarray length是否 >= k
    如果沒有 num_subarray必須歸零, 因為題目說必須adjacent
*/
class Solution {
  public:
	bool hasIncreasingSubarrays(vector<int> &nums, int k) {
		int l = 0;
		int r = 1;
		int num_subarr = 0;
		for (r = 1; r < nums.size(); ++r) {
			if (nums[r] <= nums[r - 1]) {
				// if this subarry length < k, we reset the num subarry
				if (r - l < k)
					num_subarr = 0;
				else {
					++num_subarr;
				}
				l = r;
			}
			// if consecutive subarr or subarr is longer that 2k
			if (num_subarr == 2 || r - l + 1 >= 2 * k)
				return true;
		}
		// last subarray need to be check
		if (r - l >= k)
			++num_subarr;
		return num_subarr == 2;
	}
};