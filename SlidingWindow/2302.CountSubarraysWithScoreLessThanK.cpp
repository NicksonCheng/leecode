/*1. brutal force, 直接看全部的subarray sum, O(n^3)
  2. 不要每次重算 O(n^2)
  3. 尋找合法區間, 並且每次right移動如果合法都會有r-l+1 subarray合法
*/
class Solution {
  public:
	long long countSubarrays(vector<int> &nums, long long k) {
		long long res = 0;
		int l = 0;
		long long sum = 0;
		for (int r = 0; r < nums.size(); ++r) {
			sum += nums[r];

			// 移動left直到合法
			while (sum * (r - l + 1) >= k) {
				sum -= nums[l];
				++l;
			}
			// 以right為準倒退回去會有 r-l+1的subarray
			res += (r - l + 1);
		}
		return res;
	}
};