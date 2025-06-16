// 超時
/*
    1. greedy 每次從最大的開始, 然後排序從second 累加k 直到跟max_value 相同
    最後計算frequency, O(n^2)

    2. sorting, 然後透過prefix sum跟sliding window 的概念, prefix_sum[r]
就是nums[l] ~ nums[r - 1] 變成 nums[r] 需要的operation, 如果prefix_sum[r] > k
代表不成立, 我們就left++ 直到成立,

    ps. 要注意prefix sum的算法

num     1,2,4
prefix. 0,1,1 + 2 * (r - l) = 5
    time O(nlogn), space O(n)
*/
class Solution {
  public:
	int maxFrequency(vector<int> &nums, int k) {
		int n = nums.size();
		sort(nums.begin(), nums.end()); // sort in decending order
		vector<long long> prefix_sum(n, 0);
		int l = 0;
		int most_freq = 1;
		for (int r = 1; r < n; ++r) {
			prefix_sum[r] =
			    prefix_sum[r - 1] +
			    (long long)(nums[r] - nums[r - 1]) * (long long)(r - l);
			// illegal operation
			// cout << r << " " << prefix_sum[r] << endl;
			while (l < r && prefix_sum[r] > k) {
				prefix_sum[r] -= (nums[r] - nums[l++]);
			}
			most_freq = max(most_freq, r - l + 1);
		}
		return most_freq;
	}
};