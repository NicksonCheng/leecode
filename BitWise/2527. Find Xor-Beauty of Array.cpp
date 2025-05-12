// proficient
// 20 min
/*
    1. 找所有nums 的組合, 然後照題目要求算, O(n^3)

    (i,j,k) (j,i,k) 是一樣的, xor會是0, 所以只需要紀錄num[k]的xor
*/
class Solution {
  public:
	int xorBeauty(vector<int> &nums) {
		int res = 0;
		for (int &n : nums)
			res ^= n;
		return res;
	}
};