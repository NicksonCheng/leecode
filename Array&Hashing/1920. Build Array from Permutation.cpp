/*
    O(1) space, 因為 0 <= nums[i] < nums.length, 我們用 a + b * n概念, a=
   nums[i]. b = nums[nums[i]]; 當要找原本數字就 % n, 要用新的數字就/n
*/
class Solution {
  public:
	vector<int> buildArray(vector<int> &nums) {

		// a + b * n
		int n = nums.size();

		for (int i = 0; i < nums.size(); ++i) {

			// decode a
			int new_num = nums[nums[i]] % n;

			// encode
			nums[i] = nums[i] + new_num * n;
		}
		// decode b
		for (int i = 0; i < nums.size(); ++i)
			nums[i] /= n;
		return nums;
	}
};