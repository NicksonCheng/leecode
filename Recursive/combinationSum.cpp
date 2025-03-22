#include <iostream>
using namespace std;
#include <vector>
class Solution {
  public:
	vector<vector<int>> res;
	vector<vector<int>> combinationSum(vector<int> &nums, int target) {
		vector<int> comb;
		findComb(comb, nums, target, 0);
		return res;
	}

  public:
	void findComb(vector<int> &comb, vector<int> &nums, int target, int i) {

		/* 這邊才是決定要不要放進combination
		   如果不要就return 回去 pop*/
		// terminate condition

		// find target
		if (target == 0) {
			res.push_back(comb);
			return;
		}
		// large than target or run out of index
		if (target < 0 || i >= nums.size())
			return;

		/**/

		// add nums[i] into combination
		comb.push_back(nums[i]);

		// Recur with the same index i (allowing the same number to be used
		// again)
		findComb(comb, nums, target - nums[i], i);

		// Remove the last added element to explore the next possibility
		comb.pop_back();

		/*這個num[i] 沒救了下一個i+1去看, 直到array終點*/
		// Move to the next index to explore combinations that don't include
		// nums[i]
		findComb(comb, nums, target, i + 1);
	}
};

int main() {
	Solution sol;
	vector<int> nums = {2, 5, 6, 9};
	vector<vector<int>> res = sol.combinationSum(nums, 9);
	for (int i = 0; i < res.size(); ++i) {
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
