#include <iostream>
using namespace std;
/*
    全部1跟全部-1都試試看
    遇到不符合的就change nums[i], nums[i + 1]
*/
class Solution {
  public:
	bool canMakeEqual(vector<int> &nums, int k) {
		vector<int> pos_one(nums);
		vector<int> neg_one(nums);
		int n = nums.size();
		for (int i = 0; i < n - 1; ++i) {
			if (pos_one[i] == -1) {
				if (i == n - 1)
					return false;
				else
					pos_one[i + 1] *= -1;
			}

			if (neg_one[i] == 1) {
				if (i == n - 1)
					return false;
				else
					neg_one[i + 1] *= -1;
			}
		}
		return true;
	}
};