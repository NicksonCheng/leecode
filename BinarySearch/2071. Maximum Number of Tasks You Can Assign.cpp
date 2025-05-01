// solution
/*
    greedy + binary search
    1. 先看不吃藥工人能做多少工作(sort+ binary search)
    2. 剩下還沒做事的工人去吃藥看能做多少


*/
class Solution {
  public:
	// 檢查是否可以指派 k 個任務
	bool canAssign(vector<int> &tasks, vector<int> &workers, int pills,
	               int strength, int k) {
		// 將前 k 個難度最小的任務存進 multiset（方便快速找 <= worker 的任務）
		multiset<int> taskSet(tasks.begin(), tasks.begin() + k);

		// 指派任務的工人是最強的 k 位，從 workers.size() - k 開始取
		int start = workers.size() - k;

		for (int i = 0; i < k; ++i) {
			int worker = workers[start + i];

			// 嘗試找一個難度 <= worker 的任務
			auto it = taskSet.upper_bound(worker);

			if (it == taskSet.begin()) {
				// 沒有任務 worker 能做，考慮吃藥
				if (pills == 0)
					return false; // 沒藥可吃，失敗
				--pills;          // 吃一顆藥
				// 嘗試找難度 <= worker + strength 的任務
				it = taskSet.upper_bound(worker + strength);
				if (it == taskSet.begin())
					return false; // 吃藥也做不到
				--it;             // 找到能做的最大任務
			} else {
				--it; // 找到最大可以做的任務
			}

			// 指派任務並從任務集合中移除
			taskSet.erase(it);
		}

		return true; // 所有 k 個任務都能順利指派
	}

	// 主函數：二分搜尋答案
	int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
	                  int strength) {
		sort(tasks.begin(), tasks.end());     // 將任務依照難度升序排序
		sort(workers.begin(), workers.end()); // 將工人依照體力升序排序

		int l = 0, r = min((int)tasks.size(),
		                   (int)workers.size()); // 任務與工人數量的最小值為上限
		int ans = 0;

		// 二分答案：最多可以指派幾個任務？
		while (l <= r) {
			int m = (l + r) / 2;
			// 檢查是否能成功指派 m 個任務
			if (canAssign(tasks, workers, pills, strength, m)) {
				ans = m;   // 可以，更新答案
				l = m + 1; // 嘗試更多任務
			} else {
				r = m - 1; // 不行，縮小範圍
			}
		}

		return ans; // 回傳最大可以完成的任務數量
	}
};
