/*sol 1. hashset 紀錄subset, 需要O(2^n) space
sol 2. 我們可以先sort array, 像是{1,2,2,3}, 如果遇到duplicate number,
     第一次的number就會包含第二次相同number的subset了, 所以可以跳過
*/
class Solution {
  public:
	vector<vector<int>> subsetsWithDup(vector<int> &nums) {
		vector<vector<int>> res;
		vector<int> subset;
		sort(nums.begin(), nums.end());
		recursive(res, nums, subset, 0);
		return res;
	}

	void recursive(vector<vector<int>> &res, vector<int> &nums,
	               vector<int> &subset, int i) {

		if (i == nums.size()) {
			res.push_back(subset);
			return;
		}

		// join item
		subset.push_back(nums[i]);

		recursive(res, nums, subset, i + 1);

		// do not join item
		subset.pop_back();

		// detect duplicate
		int cur_num = nums[i];
		while (i < nums.size() && nums[i] == cur_num) {
			++i;
		}
		recursive(res, nums, subset, i);
	}
};
