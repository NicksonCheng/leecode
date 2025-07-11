/*
    1. 只要不要乘到自己就好
    2. 那就左邊, 右邊個跑一次, 這樣還是O(n)
*/
class Solution {
  public:
	vector<int> productExceptSelf(vector<int> &nums) {
		int n = nums.size();
		vector<int> prefix(n, 1);
		vector<int> suffix(n, 1);
		vector<int> res(n, 1);
		for (int i = 1; i < nums.size(); ++i) {
			prefix[i] = prefix[i - 1] * nums[i - 1];
		}
		for (int i = nums.size() - 2; i >= 0; --i) {
			suffix[i] = suffix[i + 1] * nums[i + 1];
		}
		for (int i = 0; i < prefix.size(); ++i) {
			res[i] = prefix[i] * suffix[i];
		}
		return res;
	}
};
