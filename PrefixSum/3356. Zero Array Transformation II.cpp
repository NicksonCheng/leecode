// solution
/*
    diff array紀錄每次index i 要扣多少
    q[l] = +val
    q[r + 1] = -val

    1. 每k個query 都去跑一遍diff, 然後check是否滿足條件, O(M * (N + M))
    2. binary search 尋找k O(logM * (N + M))
*/
class Solution {
  public:
	int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
		int l = -1;
		int r = queries.size() - 1;

		while (l <= r) {
			int m = (r + l) / 2;
			if (zeroArray(nums, queries, m)) {
				r = m - 1;
			} else
				l = m + 1;
		}
		// cout << l << endl;
		if (l == queries.size())
			return -1;
		else
			return l + 1; // minimal used queries
	}
	bool zeroArray(vector<int> &nums, vector<vector<int>> &queries, int k) {
		vector<int> diff(nums.size() + 1, 0);

		// calculate different array,
		for (int i = 0; i <= k; ++i) {
			int l = queries[i][0];
			int r = queries[i][1];
			int val = queries[i][2];
			diff[l] += val;
			diff[r + 1] -= val;
		}

		// prefix sum for different array
		int cur = 0;
		for (int i = 0; i < nums.size(); ++i) {
			cur += diff[i];
			if (nums[i] > cur)
				return false;
		}
		return true;
	}
};