/*
    先sorting, 直接check 每個partiton 是否符合 < k

    time: sort O(nlogn) cmopared O(k), total = O(nlogn + k)
    additional space O(1)
*/
class Solution {
  public:
	vector<vector<int>> divideArray(vector<int> &nums, int k) {
		vector<vector<int>> res;
		sort(nums.begin(), nums.end());
		int i = 0;
		while (i < nums.size()) {
			int max_num = INT_MIN;
			int min_num = INT_MAX;
			for (int j = 0; j < 3; ++j) {
				max_num = max(max_num, nums[i + j]);
				min_num = min(min_num, nums[i + j]);
			}
			if (max_num - min_num <= k) {
				res.push_back({nums[i], nums[i + 1], nums[i + 2]});
			} else {
				return {};
			}
			i += 3;
		}
		return res;
	}
};