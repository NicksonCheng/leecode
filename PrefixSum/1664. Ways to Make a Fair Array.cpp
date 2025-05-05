/*
    先計算even/odd sum, 然後traverse nums 計算prefix同時也去看suffix
    刪除nums[i]後suffix odd/even 發生翻轉, 再去確認prefix_even +
   suffix_odd(suffix_even before) == prefix_odd + suffix_even(suffix_odd
   before)即可
*/
class Solution {
  public:
	int waysToMakeFair(vector<int> &nums) {
		int res = 0;
		int sum_odd = 0;
		int sum_even = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (i % 2 == 0)
				sum_even += nums[i];
			else
				sum_odd += nums[i];
		}
		int prefix_odd = 0;
		int prefix_even = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int suffix_even = sum_even - prefix_even;
			int suffix_odd = sum_odd - prefix_odd;
			if (i % 2 == 0) {
				// remove current num
				suffix_even -= nums[i];
				// reverse suffix after remove
				if (prefix_even + suffix_odd == prefix_odd + suffix_even)
					++res;

				prefix_even += nums[i];
			} else {
				// remove current num
				suffix_odd -= nums[i];
				// reverse suffix after remove
				if (prefix_even + suffix_odd == prefix_odd + suffix_even)
					++res;
				prefix_odd += nums[i];
			}
		}
		return res;
	}
};