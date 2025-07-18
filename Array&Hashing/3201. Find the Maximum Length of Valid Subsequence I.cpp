/*
    valid 定義: subsequence odd, even 交錯或是都是odd/even

    交錯就去看i + 1是否成立決定加入subsequence
*/
class Solution {
  public:
	int maximumLength(vector<int> &nums) {
		int all_odd = 0;
		int all_even = 0;
		int alter = 0;
		int parity = nums[0] % 2;
		for (int num : nums)
			num % 2 == 0 ? ++all_even : ++all_odd;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] % 2 == parity) {
				++alter;
				parity ^= 1;
			}
		}
		return max({all_even, all_odd, alter});
	}
};