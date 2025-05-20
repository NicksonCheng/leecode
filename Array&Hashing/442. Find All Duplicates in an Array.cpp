
/*
    1 <= nums[i] <= n, 沒有negative, 可以用neg來做重複
    遇到num[i]就去看 num[num[i]] 是否為neg(重複),
   不是就設定為neg下次遇到就是重複了
*/
class Solution {
  public:
	vector<int> findDuplicates(vector<int> &nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			int idx = abs(nums[i]) - 1;
			if (nums[idx] < 0) {
				res.push_back(abs(nums[i]));
			}
			nums[idx] = -nums[idx];
		}
		return res;
	}
};