// solution
/*
    先check左右兩邊哪一邊是acending order

    看target是否在這個order裡面(不是的話就是在另一邊)
*/
class Solution {
  public:
	int search(vector<int> &nums, int target) {
		int l = 0;
		int r = nums.size() - 1;

		while (l <= r) {
			int m = l + (r - l) / 2;

			if (nums[m] == target)
				return true;

			// nums[l] == nums[m] 有可能是duplicate, 移動到不相同為止
			while (nums[l] == nums[m] && l < m)
				++l;
			// left side is ordered
			if (nums[l] <= nums[m]) {
				if (target >= nums[l] && target < nums[m])
					r = m - 1;
				else
					l = m + 1;
			}
			// right side is ordered
			else {
				if (target <= nums[r] && target > nums[m])
					l = m + 1;
				else
					r = m - 1;
			}
		}
		return false;
	}
};