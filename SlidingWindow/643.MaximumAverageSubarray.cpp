
// proficient
/*
    注意left - 1問題
*/
class Solution {
  public:
	double findMaxAverage(vector<int> &nums, int k) {
		double sum = 0.0;
		double max_sum = 0.0;
		for (int i = 0; i < k; ++i) {
			sum += nums[i];
		}
		max_sum = sum;
		int l = 1;
		int r = k;

		while (r < nums.size()) {
			sum = sum + nums[r] - nums[l - 1];
			max_sum = max(sum, max_sum);
			++l;
			++r;
		}
		return max_sum / k;
	}
};