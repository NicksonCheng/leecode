// proficient
/*
    1. brutal force, 直接每個都算, O(n * d)
    2.
*/
class Solution {
  public:
	int findNumbers(vector<int> &nums) {
		int res = 0;
		for (int &num : nums) {
			int digits = 0;
			while (num > 0) {
				++digits;
				num /= 10;
			}
			if (digits % 2 == 0)
				++res;
		}
		return res;
	}
};