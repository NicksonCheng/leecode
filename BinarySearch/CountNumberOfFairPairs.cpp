/*
1. 暴力法, 所有pair都去比較, O(n^2)
2. 先sorting, two pointer i, k, 移動k 去尋找upper bound, lower bound(Binary
Search)
    lower_bound：找出vector中「大於或等於」val的「最小值」的位置：
    upper_bound：找出vector中「大於」val的「最小值」的位置：
    ex 0,1,4,4,5,7  lower_bound 3 在index 2, upper_bound 6在index 5
*/

class Solution {
  public:
	long long countFairPairs(vector<int> &nums, int lower, int upper) {
		sort(nums.begin(), nums.end()); // 先排序
		long long count = 0;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			int minVal = lower - nums[i];
			int maxVal = upper - nums[i];

			int l = lower_bound(nums, i + 1, n, minVal);
			int r = upper_bound(nums, i + 1, n, maxVal);

			count += r - l;
		}
		return count;
	}

  private:
	int lower_bound(const vector<int> &nums, int l, int r, int target) {
		// find the num >= target
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] >= target) {
				// find ans index or too large
				r = m;
			} else {
				// too small
				l = m + 1;
			}
		}
		return l;
	}

	int upper_bound(const vector<int> &nums, int l, int r, int target) {
		// find the num > target
		while (l < r) {
			int m = (l + r) / 2;
			if (nums[m] > target) {
				// too large or find ans index
				r = m;
			} else
				l = m + 1; // too small
		}
		return l;
	}
};

/* STL version*/
class Solution {
  public:
	long long countFairPairs(vector<int> &nums, int lower, int upper) {
		sort(nums.begin(), nums.end()); // 先排序
		long long count = 0;
		int n = nums.size();

		for (int i = 0; i < n; ++i) {
			int minVal = lower - nums[i];
			int maxVal = upper - nums[i];

			// 在 [i+1, n) 範圍內找符合條件的 j 值數量
			auto l = lower_bound(nums.begin() + i + 1, nums.end(), minVal);
			auto r = upper_bound(nums.begin() + i + 1, nums.end(), maxVal);

			count += r - l;
		}
		return count;
	}
};
