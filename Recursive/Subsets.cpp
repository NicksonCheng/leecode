/*
recursive, every recursion decide whether add this number into subset or not
*/

class Solution {
  public:
	vector<vector<int>> subsets(vector<int> &nums) {
		vector<vector<int>> res;
		vector<int> subset;
		findSubsets(res, subset, nums, 0);
		return res;
	}

  private:
	void findSubsets(vector<vector<int>> &res, vector<int> &subset,
	                 vector<int> &nums, int curr_idx) {

		// terminate condiction
		if (curr_idx == nums.size()) {
			res.push_back(subset);
			return;
		}

		// add nums[i]
		subset.push_back(nums[curr_idx]);
		findSubsets(res, subset, nums, curr_idx + 1);
		subset.pop_back();
		findSubsets(res, subset, nums, curr_idx + 1);
		// do not add nums[i]
	}
};
