/*
    min heap to keep max_k element
    然後將index 倒入 另一個 min_heap, 因為最後要return K個最大值
    time O(nlogk)
*/
#define Pair pair<int, int>
class Solution {
  public:
	vector<int> maxSubsequence(vector<int> &nums, int k) {
		priority_queue<Pair, vector<Pair>, greater<>>
		    min_heap; // over k we pop the element
		priority_queue<Pair, vector<Pair>, greater<>> min_heap_idx;
		for (int i = 0; i < nums.size(); ++i) {
			min_heap.push({nums[i], i});
			if (min_heap.size() > k)
				min_heap.pop();
		}
		vector<int> res;
		while (!min_heap.empty()) {
			auto [num, i] = min_heap.top();
			min_heap_idx.push({i, num});
			min_heap.pop();
		}
		while (!min_heap_idx.empty()) {
			res.push_back(min_heap_idx.top().second);
			min_heap_idx.pop();
		}
		return res;
	}
};