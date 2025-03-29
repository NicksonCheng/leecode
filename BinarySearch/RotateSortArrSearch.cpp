/*
    1. 先找最小的值(pivot)
    2. 判斷我們要找的值是否大於最後一個
        1. 是, 必在pivot 左邊
        2. 不是, 必在pivot右邊
*/
class Solution {
  public:
	int search(vector<int> &nums, int target) {
		int l = 0;
		int r = nums.size() - 1;

		// find min first
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] > nums.back())
				l = m + 1;
			else {
				r = m - 1;
			}
		}
		int pivot = l;
		l = 0;
		r = nums.size() - 1;
		if (target <= nums[r]) {
			l = pivot;
		} else {
			r = pivot;
		}
		while (l <= r) {
			int m = (l + r) / 2;
			if (nums[m] < target)
				l = m + 1;
			else if (nums[m] > target)
				r = m - 1;
			else
				return m;
		}
		return -1;
	}
};
