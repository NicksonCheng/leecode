// proficient
/*

    overlap就把end比較長的處理掉
    優化: 不用存上一個vector interval, 存他的end就好
    26 minute
*/
class Solution {
  public:
	// 重點: pass by value, 會不斷複製vector導致效能變差
	static bool sort_start(vector<int> &a, vector<int> &b) {
		return a[0] < b[0];
	}
	int eraseOverlapIntervals(vector<vector<int>> &intervals) {
		sort(intervals.begin(), intervals.end(), sort_start);
		int res = 0;
		int i = 1;
		int last_end = intervals[0][1];
		while (i < intervals.size()) {

			// 刪除overlap的interval
			if (intervals[i][0] < last_end) {
				++res;

				if (last_end > intervals[i][1])
					last_end = intervals[i][1];
			} else
				last_end = intervals[i][1];
			++i;
		}
		return res;
	}
};