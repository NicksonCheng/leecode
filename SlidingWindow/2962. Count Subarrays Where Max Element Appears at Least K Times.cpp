/*
    sliding window, 每次移動right, 如果count >=k, 就移動left 直到 < k,
    然後[0~start]都會是合法區間, start = l - 1;
*/
class Solution {
  public:
	long long countSubarrays(vector<int> &nums, int k) {
		int n = nums.size();
		int max_val = *max_element(nums.begin(), nums.end());
		long long res = 0;
		int count = 0, l = 0;

		for (int r = 0; r < n; ++r) {
			if (nums[r] == max_val)
				++count;

			while (count >= k) {
				if (nums[l] == max_val)
					--count;
				++l;
			}

			// count < k，所以剛剛合法的是 [0, l-1]
			// 所以合法子陣列數為 l
			res += l;
		}

		return res;
	}
};
