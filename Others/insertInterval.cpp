/*1. 每次都跟 i check 是否overlap
3. end如果比start_i還小代表 interval i 在這個interval 之後
4. start 如果比end_i 還大代表interval i 在這個interval 之前
5. 都不是就是overlap, 那就直接更新interval i
*/
class Solution {
  public:
	vector<vector<int>> insert(vector<vector<int>> &intervals,
	                           vector<int> &newInterval) {
		vector<vector<int>> res;
		if (intervals.empty()) {
			intervals.push_back(newInterval);
			return intervals;
		}

		for (int i = 0; i < intervals.size(); ++i) {
			// new_end < start_i(newInterval 比 interval i 還小,
			// 就直接插入這個位置 return)
			if (newInterval[1] < intervals[i][0]) {
				res.push_back(newInterval);

				// 後面都複製貼上
				copy(intervals.begin() + i, intervals.end(),
				     back_inserter(res));
				return res;
			}

			// new_start > end_i (newInterval 比 interval i 還大, 繼續往下找)
			else if (newInterval[0] > intervals[i][1]) {
				res.push_back(intervals[i]);
			}
			// overlap(擴充interval)
			else {
				vector<int> updated_interval;
				int min_start = min(intervals[i][0], newInterval[0]);
				int max_end = max(intervals[i][1], newInterval[1]);
				newInterval[0] = min_start;
				newInterval[1] = max_end;
			}
		}
		// 找到最底就把當前擴充完的interval插入最尾端
		res.push_back(newInterval);
		return res;
	}
};
