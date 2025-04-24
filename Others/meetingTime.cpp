/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

/* 1. 先全部sort start
    2. 相鄰兩個interval比較, 如果有overlap, return false
    3. 記得custom soring的用法
*/
class Solution {
  public:
	bool canAttendMeetings(vector<Interval> &intervals) {
		if (intervals.empty())
			return true;
		sort(intervals.begin(), intervals.end(), cmp);
		for (int i = 0; i < intervals.size() - 1; ++i) {
			// overlap
			if (intervals[i + 1].start < intervals[i].end)
				return false;
		}
		return true;
	}

  private:
	static bool cmp(Interval i_1, Interval i_2) {
		// ascending sort
		return i_1.start < i_2.start;
	}
};
