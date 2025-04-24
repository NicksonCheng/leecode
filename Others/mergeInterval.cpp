/*
    1. 先sort interval by start[i], time complexity O(nlong)
   overlap 定義start[i] < start[i+1] < end[i]
               start[i] < end[i+1]  < end[i]
*/
class Solution {
  public:
	static bool sort_start(vector<int> a, vector<int> b) { return a[0] < b[0]; }
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		vector<vector<int>> res;
		// sort interval by begin
		sort(intervals.begin(), intervals.end());

		// merge overlapped interval
		vector<int> cur_interval = intervals[0];
		for (int i = 1; i < intervals.size(); ++i) {
			int s = intervals[i][0];
			int e = intervals[i][1];
			int l_s = cur_interval[0];
			int l_e = cur_interval[1];
			if (s <= l_e) {
				// expand overlapped interval
				cur_interval = {l_s, max(l_e, e)};
			} else {
				// if not overlap, push into response and update current
				// compared interval
				res.push_back(cur_interval);
				cur_interval = intervals[i];
			}
		}
		// remerber to push last interval
		res.push_back(cur_interval);
		return res;
	}
};