// slinding window, O(n)
class Solution {
  public:
	int countSubarrays(vector<int> &nums) {
		int res = 0;
		for (int i = 0; i + 2 < nums.size(); ++i) {
			if (nums[i + 1] == (nums[i] + nums[i + 2]) * 2)
				++res;
		}
		return res;
	}
};