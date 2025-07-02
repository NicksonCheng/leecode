/*
    sol.1 暴力法, 每個num[i] 都去找相同數字nums[j] 跟 nums[j] = nums[i] +
   1的次數, 然後決定最大值, O(n^2) sol.2 hashtable先算出每個num[i] 有多少個,
   如果count[nums[i] + 1] 存在, 那subseq 就會是count[nums[i]] + count[nums[i] +
   1] time O(n), space O(n)

    sol.3 sorting, 然後two pointer 尋找符合 nums[r] - nums[l] == 1的合法windows

*/
/* Hashtable */
class Solution {
  public:
	int findLHS(vector<int> &nums) {
		unordered_map<int, int> num_cnt;
		int max_subseq = 0;
		for (int &num : nums)
			++num_cnt[num];
		for (auto &nc : num_cnt) {
			if (num_cnt.count(nc.first + 1) > 0) {
				int max_val = num_cnt[nc.first + 1];
				max_subseq = max(max_subseq, nc.second + max_val);
			}
		}
		return max_subseq;
	}
};
/* Sorting + Two pointer*/
class Solution {
  public:
	int findLHS(vector<int> &nums) {
		sort(nums.begin(), nums.end());
		int l = 0;
		int max_subseq = 0;
		for (int r = 0; r < nums.size(); ++r) {
			while (nums[r] - nums[l] > 1)
				++l;

			// avoid repeat nums like [1,1,1,1]
			if (nums[r] - nums[l] == 1)
				max_subseq = max(max_subseq, r - l + 1);
		}
		return max_subseq;
	}
};