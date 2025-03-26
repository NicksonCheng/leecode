// 倒序回來看能不能跳
// 可以跳就更新目前的成功idx
class Solution {
  public:
	bool canJump(vector<int> &nums) {

		int success_idx = nums.size() - 1;
		for (int i = nums.size() - 2; i >= 0; --i) {
			if (i + nums[i] == success_idx)
				success_idx = i;
		}
		return success_idx == 0;
	}
};
