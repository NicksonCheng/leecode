// hint
// 超過30分鐘
/*
    1. 先decending sorting 找到最前面的車隊
    2. 計算每台車到達終點需要的時間
    3. 透過monotonic stack 去尋找下一個比自己大的element
*/
class Solution {
  public:
	static bool cmp(pair<int, int> p1, pair<int, int> p2) {
		return p1.first > p2.first;
	}
	int carFleet(int target, vector<int> &position, vector<int> &speed) {

		// decending sorting by position
		int n = position.size();
		vector<pair<int, int>> pos_speed(n);
		for (int i = 0; i < position.size(); ++i) {
			pos_speed[i] = {position[i], speed[i]};
		}
		sort(pos_speed.begin(), pos_speed.end(), cmp);

		// calculate the required time to reach target position

		vector<double> required_time(n, 0);
		for (int i = 0; i < n; ++i) {
			double t = (double)(target - pos_speed[i].first) /
			           (double)pos_speed[i].second;
			required_time[i] = t;
		}
		// stack to search next large element
		// >= stack 為同車隊, < stack 為另一車隊
		stack<double> fleet;
		for (int i = 0; i < n; ++i) {
			double t = required_time[i];
			if (fleet.empty() || fleet.top() < t)
				fleet.push(t);
		}
		return fleet.size();
	}
};
