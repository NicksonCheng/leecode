/*
    1. brutal force, calculate all zero/one in all subarray, time O(n^2)

    2. 當成是-1/1 走路, 用 prefix sum + hash map 儲存第一次出現某個總和的位置。
若同一個總和再度出現，代表中間這段的總和為 0。 O(n)
*/
class Solution {
  public:
	int findMaxLength(vector<int> &nums) {
		unordered_map<int, int> prefix_sum; // {sum, index j}
		int sum = 0;
		int max_len = 0;
		prefix_sum[0] = -1;
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] == 0 ? --sum : ++sum;
			// cout << sum << endl;
			if (prefix_sum.count(sum) > 0) {
				int j = prefix_sum[sum];
				max_len = max(i - j, max_len);
			} else
				prefix_sum[sum] = i;
		}
		return max_len;
	}
};