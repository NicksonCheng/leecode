/*
    1. sort, 然後traverse, 每次都紀錄目前consecutive 次數, O(nlogn)
*/

class Solution {
  public:
	int longestConsecutive(vector<int> &nums) {
		if (nums.size() == 0)
			return 0;
		sort(nums.begin(), nums.end());
		int max_count = 0;
		int cur = 1;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] == (nums[i - 1] + 1))
				++cur;
			else if (nums[i] == nums[i - 1])
				continue;
			else {
				max_count = max(max_count, cur);
				cur = 1;
			}
		}
		max_count = max(max_count, cur);
		return max_count;
	}
};