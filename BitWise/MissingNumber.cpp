/*
    1. num ^ num = 0
    2. res ^ (0~n) first;
    3. res ^(num[0] ~num[n-1]) find the single number
*/

class Solution {
  public:
	int missingNumber(vector<int> &nums) {
		int res = 0 ^ nums.size();
		for (int i = 0; i < nums.size(); ++i) {
			res = res ^ i ^ nums[i];
		}
		return res;
	}
};
