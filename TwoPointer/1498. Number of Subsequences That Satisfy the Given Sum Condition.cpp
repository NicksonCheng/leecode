/*

    sol.2 先sorting nums, 然後two pointer 找到min/max 的element 計算是否
    max + min <= target, 如果符合, 就left++ 找更大的, 反之right--
*/
class Solution {
  public:
	int numSubseq(vector<int> &nums, int target) {
		int n = nums.size();
		sort(nums.begin(), nums.end());
		int sum = 0;
		int l = 0;
		int r = n - 1;
		int modolo = 1e9 + 7;
		vector<int> power(n, 1);
		for (int i = 1; i < n; ++i) {
			power[i] = (power[i - 1] * 2) % modolo;
		}
		while (l <= r) {
			if (nums[l] + nums[r] <= target) {
				// [r - l] 區間的 subsequemce都合法,中間數字可用可不用, 會有2^(r
				// - l) answer
				sum = (sum + power[r - l]) % modolo;
				++l;
			} else
				--r;
		}
		return sum;
	}
};