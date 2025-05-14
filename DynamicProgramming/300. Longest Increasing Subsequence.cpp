// solution
/*
1. top down
*/
/*
    每次決定要拿還是要跳過, 並且記錄上一個拿到index

    dp[i][last_idx] 代表在這個index, last element index下的max subsequence
time: O(n^2)
space: O(n^2)
    */
class Solution {
  public:
	vector<vector<int>> dp;
	int lengthOfLIS(vector<int> &nums) {
		int n = nums.size();
		dp.resize(n, vector<int>(n, -1));
		return dfs(nums, 0, -1);
	}
	int dfs(vector<int> &nums, int i, int last_idx) {
		if (i == nums.size())
			return 0;
		if (dp[i][last_idx + 1] != -1)
			return dp[i][last_idx + 1];
		// skip this element
		int LIS = dfs(nums, i + 1, last_idx);

		// take this element
		if (last_idx == -1 || nums[i] > nums[last_idx]) {
			LIS = max(LIS, dfs(nums, i + 1, i) + 1);
		}
		// -1 不能算
		dp[i][last_idx + 1] = LIS;
		return LIS;
	}
};
/*
2. bottom up:
dp[i] 表示以 nums[i] 結尾的 LIS 長度
每次往前看所有 j < i 的情況，找出能延伸的 subsequence
time: O(n^2)
space: O(n)
*/
class Solution {
  public:
	int lengthOfLIS(vector<int> &nums) {
		int n = nums.size();
		vector<int> dp(n, 1);
		int max_len = 0;
		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < i; ++j) {
				if (nums[j] < nums[i]) {
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
			max_len = max(max_len, dp[i]);
		}
		return max_len;
	}
};

/*
greedy + binary search（貪心 + 二分搜） 的方法

1. lis 中的元素不一定是真正的 LIS，但其 長度 就是正確的 LIS 長度。
2. lis[i] 代表長度為 i+1 的遞增子序列的「最小可能尾部」
3. 如果num[i] > list.end(), 代表可以繼續插入num給list
   反之就去找lower_bound然後取代那個值(代表從那個地方開始的sequence end變更小了)
   ex: [2,3,5,7,4]
   list 為 [2,3,5,7], 4 < list.end() = 7, lower_bound 為5(idx = 2)
   list變成[2,3,4,7]-> [2,3,4] 比 [2,3,5]更值得擴充`
   使用 lower_bound（二分搜尋）將時間複雜度壓到 O(log n)
*/
class Solution {
  public:
	int lengthOfLIS(vector<int> &nums) {
		vector<int> lis; // 用來維護一個"潛在的LIS尾部"
		for (int num : nums) {
			// 在 lis 中找第一個 >= num 的位置
			auto it = lower_bound(lis.begin(), lis.end(), num);
			if (it == lis.end()) {
				// num 比所有都大，可以延長 LIS
				lis.push_back(num);
			} else {
				// 用 num 更新現有 LIS 尾部（保持越小越好）
				*it = num;
			}
		}
		return lis.size();
	}
};
