/*
    find lower_bound and upper_bound
    result = upper - lower
*/
class Solution {
  public:
	vector<int> searchRange(vector<int> &nums, int target) {
		int n = nums.size();
		if (n == 0)
			return {-1, -1};
		int start = lower_bound(nums, 0, n, target);
		int end = upper_bound(nums, 0, n, target);
		if (start == n || nums[start] != target)
			return {-1, -1};
		return {start, end - 1};
	}
	int lower_bound(vector<int> &nums, int l, int r, int v) {
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] >= v)
				r = m;
			else
				l = m + 1;
		}
		return l;
	}
	int upper_bound(vector<int> &nums, int l, int r, int v) {
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] > v)
				r = m;
			else
				l = m + 1;
		}
		return l;
	}
};