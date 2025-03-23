class Solution {
  public:
	/* XOR could check num is same or not(return 0)*/
	int singleNumber(vector<int> &nums) {
		int res = 0; // 0 xor num = num

		// identical num could be discharge, leave number appears only once
		for (int &num : nums) {
			res ^= num;
		}
		return res;
	}
};
