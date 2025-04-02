
class Solution {
  public:
	bool containsNearbyDuplicate(vector<int> &nums, int k) {
		unordered_map<int, int> nums_idx;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums_idx.find(nums[i]) != nums_idx.end()) {

				if (i - nums_idx[nums[i]] <= k)
					return true;
			}

			nums_idx[nums[i]] = i;
		}
		return false;
	}
};