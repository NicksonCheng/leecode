/*
    1. brutal force, sldiing window exapdn right, narrow left, then check all
   subarray and calculate all distance time: O(n^2)

    2. we used heap to maintain max/min value in windows(by index), and if
   current distance(max - min) > limit, narrow down until <= limit
    time O(nlogn)

    3. monotonic queue, heap 會造成多餘的log(n) 計算,
       我們同時維護max/min dqueue, 超出limit 就不斷移動left 直到max/min 符合條件

*/
#include <iostream>
using namespace std;
#define Pair pair<int, int>
class Solution {
  public:
	int longestSubarray(vector<int> &nums, int limit) {
		priority_queue<Pair> max_heap;
		priority_queue<Pair, vector<Pair>, greater<>> min_heap;
		int l = 0;
		int max_len = 0;
		for (int r = 0; r < nums.size(); ++r) {
			max_heap.push({nums[r], r});
			min_heap.push({nums[r], r});

			while (l < r && !max_heap.empty() && !min_heap.empty() &&
			       max_heap.top().first - min_heap.top().first > limit) {
				while (max_heap.top().second <= l)
					max_heap.pop();
				while (min_heap.top().second <= l)
					min_heap.pop();
				++l;
			}
			max_len = max(max_len, r - l + 1);
		}
		return max_len;
	}
};

class Solution {
  public:
	int longestSubarray(vector<int> &nums, int limit) {
		deque<int> max_q;
		deque<int> min_q; // save index
		int l = 0;
		int max_len = 0;
		for (int r = 0; r < nums.size(); ++r) {

			// maintain the restrict increase/decrease
			while (!max_q.empty() && nums[max_q.front()] < nums[r])
				max_q.pop_front();
			while (!min_q.empty() && nums[min_q.front()] > nums[r])
				min_q.pop_front();
			max_q.push_front(r);
			min_q.push_front(r);
			// if current max/min over the limit, narrow left window utils less
			// than limit
			while (!max_q.empty() && !min_q.empty() &&
			       nums[max_q.back()] - nums[min_q.back()] > limit) {
				if (max_q.back() <= l)
					max_q.pop_back();
				if (min_q.back() <= l)
					min_q.pop_back();
				++l;
			}
			max_len = max(max_len, r - l + 1);
		}
		return max_len;
	}
};