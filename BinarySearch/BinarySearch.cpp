#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	int search(vector<int> &nums, int target) {
		int left = 0;
		int right = nums.size() - 1;
		while (left <= right) {
			/* code */
			int middle = (left + right) / 2;
			if (target > nums[middle])
				left = middle + 1;
			else if (target < nums[middle])
				right = middle - 1;
			else
				return middle;
		}

		return -1;
	}
};
int main() {
	Solution sol;
	vector<int> nums = {2, 5};
	cout << sol.search(nums, 2) << endl;
	return 0;
}