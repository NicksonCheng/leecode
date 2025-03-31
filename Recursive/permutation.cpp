/*
    每次recursive找不在permutation的item
*/
class Solution {
  public:
	vector<vector<int>> res;
	vector<vector<int>> permute(vector<int> &nums) {
		vector<int> permu;
		recursive(nums, permu);
		return res;
	}
	void recursive(vector<int> &nums, vector<int> permu) {
		if (permu.size() == nums.size()) {
			res.push_back(permu);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (find(permu.begin(), permu.end(), nums[i]) == permu.end()) {
				permu.push_back(nums[i]);
				recursive(nums, permu);
				permu.pop_back();
			}
		}
	}
};
