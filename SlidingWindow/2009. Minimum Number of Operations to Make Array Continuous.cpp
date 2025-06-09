/*
        sol.1 sorting , 然後去掉duplicated
        然後slding window找最大contiguous subarray,
        sorting time O(nlogn)
        slding window time O(n)
    ans = n - max_subarr
*/
class Solution {
  public:
	int minOperations(vector<int> &nums) {
		// remove duplicated
		int n = nums.size();
		unordered_set<int> s(nums.begin(), nums.end());
		vector<int> dis_nums(s.begin(), s.end());
		sort(dis_nums.begin(), dis_nums.end());

		int max_windows = 0;
		int l = 0;
		// sliding window find max window length
		for (int r = 0; r < dis_nums.size(); ++r) {
			while (dis_nums[r] - dis_nums[l] >= n) {
				// dis_nums[r] not legal, narrow down left
				++l;
			}
			max_windows = max(max_windows, r - l + 1);
		}
		// n - max_windows = number of change
		return n - max_windows;
	}
};