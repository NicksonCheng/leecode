// solution
/*
    題目問題在於能夠組出p組maximum difference, 然後這p組中的最大必須是最小

    透過binary search 每次給定一個maximum difference看能不能組出pair p組 都 <
   這個max_diff 不行-> move right 可以 -> move left
*/
class Solution {
  public:
	int minimizeMax(vector<int> &nums, int p) {
		sort(nums.begin(), nums.end());
		int left = 0;
		int right = nums.back() - nums[0];

		while (left <= right) {
			int m = left + (right - left) / 2;
			if (isValid(nums, p, m))
				right = m - 1;
			else
				left = m + 1;
		}
		return left;
	}
	bool isValid(vector<int> &nums, int p, int max_diff) {
		int count = 0;
		int i = 0;
		while (i + 1 < nums.size()) {
			if (nums[i + 1] - nums[i] <= max_diff) {
				++count;
				i += 2;
			} else
				++i;
		}
		return count >= p;
	}
};