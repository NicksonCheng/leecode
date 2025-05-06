// hint
/*
    1.
    max_heap儲存目前k window下的max value,
    滑動window一但max value index 不在window裡面,
    就持續pop直到max_value存在window
    time complexity O(n)->滑動 O(logn)->尋找window最大值----> O(nlogn)
    space O(n)
   2.
   monotonic queue 紀錄目前queue裡面最大值(遞減)
   deque的方式每次看front是否超出queue範圍
   time complexity O(n) 大家都只進出dequeue一次
*/
class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		// {num, idx}
		priority_queue<pair<int, int>> max_heap;
		vector<int> result;
		for (int i = 0; i < nums.size(); ++i) {
			max_heap.push({nums[i], i});
			// 先push window size
			if (max_heap.size() < k)
				continue;
			// max value 超出window範圍
			while (i - max_heap.top().second >= k) {
				max_heap.pop();
			}

			// 目前max value push 到result
			result.push_back(max_heap.top().first);
		}
		return result;
	}
};

/* monotonic queue 紀錄目前queue裡面最大值(遞減)
   deque的方式每次看front是否超出queue範圍
   time complexity O(n) 大家都只進出dequeue一次
*/
class Solution {
  public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k) {
		deque<pair<int, int>> window;
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i) {
			// monotonic queue
			while (!window.empty() && window.back().first < nums[i]) {
				window.pop_back();
			}
			// overflow window
			while (!window.empty() && i - window.front().second >= k)
				window.pop_front();
			if (i >= k - 1) {
				// self is max value
				if (window.empty())
					res.push_back(nums[i]);
				else
					res.push_back(window.front().first); // 最前面是最大的
			}
			window.push_back({nums[i], i});
		}
		return res;
	}
};