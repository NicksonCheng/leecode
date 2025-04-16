// hint
/*
    1. 暴力法 O(n^3)
    2. two pointer + fixed number O(n^2)
*/
class Solution {
  public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size(); ++i) {

			// i-1 == i 必須跳過, 因為i-1 並定search過
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			int l = i + 1;
			int r = nums.size() - 1;
			int target = -(nums[i]);
			while (l < r) {

				if (nums[l] + nums[r] < target) {
					++l;
				} else if (nums[l] + nums[r] > target) {
					--r;
				}

				else {
					int l_num = nums[l];
					int r_num = nums[r];
					vector<int> ans = {nums[l], nums[i], nums[r]};
					res.push_back(ans);
					--r;
					++l;

					// skip duplicate, 因為l, r
					// 不管哪個遇到相同的必定會有duplicate
					while (l < r && nums[l] == l_num)
						++l;
					while (l < r && nums[r] == r_num)
						--r;
				}
			}
		}
		return res;
	}
};
