// solution
// (interest[j] - interest[i]) % modulo == k
class Solution {
  public:
	long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
		unordered_map<int, long long> mod_count;
		mod_count[0] = 1; // 因為 prefix_sum - k == 0 也是合法解
		long long res = 0;
		int prefix = 0;

		for (int num : nums) {
			// 如果 num 是 interesting 就 +1
			prefix += (num % modulo == k ? 1 : 0);
			int cur_mod = prefix % modulo;

			// 找尋之前出現過 prefix_sum % modulo == (cur_mod - k + modulo) %
			// modulo 的次數
			int target = (cur_mod - k + modulo) % modulo;
			res += mod_count[target];

			// 記錄目前的 prefix_sum % modulo
			mod_count[cur_mod]++;
		}

		return res;
	}
};
