// solution
/*
    sorting intervals, queries

    min_heap紀錄最小interval
    每個queries 都去push 值的ㄠ interval[start] > q[i], 然後pop出距離最小的

    如果interval[end] < q[i] 不能用

    time O(nlogn + mlogm)
*/
#define Pair pair<int, int>
struct Cmp {
	bool operator()(Pair &a, Pair &b) {
		return (a.second - a.first + 1) > (b.second - b.first + 1);
	}
};
class Solution {
  public:
	vector<int> minInterval(vector<vector<int>> &intervals,
	                        vector<int> &queries) {
		vector<Pair> qs;
		for (int i = 0; i < queries.size(); ++i)
			qs.push_back({queries[i], i});
		sort(intervals.begin(), intervals.end());
		sort(qs.begin(), qs.end());
		priority_queue<Pair, vector<Pair>, Cmp> min_heap;
		vector<int> res(queries.size(), -1);
		int i = 0;
		for (auto &q : qs) {
			// find start < q interval
			while (i < intervals.size() && intervals[i][0] <= q.first) {
				min_heap.push({intervals[i][0], intervals[i][1]});
				++i;
			}

			// pop interval end < q
			while (!min_heap.empty() && min_heap.top().second < q.first)
				min_heap.pop();

			if (!min_heap.empty()) {
				auto [s, e] = min_heap.top();
				res[q.second] = e - s + 1;
			}
		}
		return res;
	}
};