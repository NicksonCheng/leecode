/*1. 直接遇到重複就remove, O(n^2)
  2. two pointer, 遇到不同的number就交換num[replace_idx] = num[i], replace_idx+=
*/
class Solution {
  public:
	int removeDuplicates(vector<int> &nums) {
		int replace_idx = 1;
		int cur_num = nums[0];
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] != cur_num) {
				nums[replace_idx] = nums[i];
				++replace_idx;
				cur_num = nums[i];
			}
		}
		nums.resize(replace_idx);
		return replace_idx;
	}
};