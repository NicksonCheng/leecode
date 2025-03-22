class Solution {
  public:
	int findMin(vector<int> &nums) {
		int left = 0;
		int right = nums.size() - 1;

		while (left <= right) {
			int middle = (left + right) / 2;
			if (nums[middle] > nums.back()) {
				// min must be right
				left = middle + 1;
			} else {
				// min must be left
				right = middle - 1;
			}
		}
		return nums[left];
	}