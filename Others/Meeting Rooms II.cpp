// hint
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
/*
    1. 分別把start, end 抓出來sorting
    2. two pointer, s,e,
        當s[i] < e[i] 代表s[i]會議必須要另開房間因為end[i] 還在開會
        當s[i] > e[i] 代表s[i]會議可以再e[i]結束後使用, ++e[i]

*/
class Solution {
  public:
	int minMeetingRooms(vector<Interval> &intervals) {
		int n = intervals.size();
		vector<int> start;
		vector<int> end;
		for (auto &i : intervals) {
			start.push_back(i.start);
			end.push_back(i.end);
		}
		sort(start.begin(), start.end());
		sort(end.begin(), end.end());

		// schedule meeting root
		int s = 0;
		int e = 0;
		int rooms = 0;
		while (s < n) {
			if (start[s] < end[e])
				++rooms;
			else
				++e;
			++s;
		}
		return rooms;
	}
};
