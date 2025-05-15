// solution
/*
    dp[i] 為 subseq(0,i) 的max sum

    dp[i] = nums[i] + max(0, dp[i - k], dp[i - k +
1]).....(如果前面subseq都是<0不如從自己開始)

📦 Monotonic Queue 解釋
我們想每次快速找到 dp[j] 最大值（在範圍 [i - k, i - 1] 內）來轉移 dp[i]。

用 deque（雙端佇列）來維護一個「滑動視窗」的最大值。

deque 中存的是 索引 j，並且維持 dp[j] 遞減，這樣 dq.front() 就是最大值


Monotonic Queue	✅	O(n)	O(k)	最快、最常見解法
Max Heap	✅	O(n log k)	O(k)	稍慢但更直觀

*/
class Solution {
  public:
	int constrainedSubsetSum(vector<int> &nums, int k) {
		vector<int> dp;
		deque<int> subseq_heap; // monotonic queue strictly decrease
		for (int &n : nums)
			dp.push_back(n);

		// 從i-k ~ i 找max subseq sum
		int max_subseq = dp[0];
		for (int i = 0; i < nums.size(); ++i) {

			// check if back is outdate (i - j > k)
			while (!subseq_heap.empty() && i - subseq_heap.front() > k)
				subseq_heap.pop_front();

			// nums[i] + max(0, dp[i - k] ...dp[i - 1]) 如果前面都 < 0
			// 不如從自己開始
			if (!subseq_heap.empty())
				dp[i] = max(dp[i], dp[i] + dp[subseq_heap.front()]);
			max_subseq = max(dp[i], max_subseq);

			// maintain monotonic queue
			while (!subseq_heap.empty() && dp[i] > dp[subseq_heap.back()])
				subseq_heap.pop_back();
			subseq_heap.push_back(i);
		}
		return max_subseq;
	}
};