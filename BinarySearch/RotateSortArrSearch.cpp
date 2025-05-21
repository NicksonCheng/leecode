
/*
    one-pass 先check左右兩邊哪一邊是acending order

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
				return m;
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
		return -1;
	}
};
/*
    two pass
    先找最小的值(pivot)
    判斷我們要找的值是否大於最後一個
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
