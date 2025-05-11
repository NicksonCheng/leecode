// solution
/*

*/
class DetectSquares {
  public:
	unordered_map<int, unordered_map<int, int>> points;

	DetectSquares() {}

	void add(vector<int> point) {
		int x = point[0], y = point[1];
		++points[x][y];
	}

	int count(vector<int> point) {
		int x = point[0], y = point[1];
		int res = 0;

		if (!points.count(x))
			return 0;

		// 遍歷所有與 x 相同的點 (x, y1)
		for (auto &[y1, cnt] : points[x]) {
			if (y1 == y)
				continue; // 必須是對角，跳過自己

			int d = y1 - y; // 正方形邊長

			for (int dx : {-d, d}) {
				int x2 = x + dx;

				// y2 存在
				if (points.count(x2)) {
					int y2 = y;
					// cnt 是 x1,y1 count
					// cnt(x1,y1) * cnt(x2,y2) * cnt[x2][y1]
					res += cnt * points[x2][y2] *
					       points[x2][y1]; // check x2 y1是否存在
				}
			}
		}

		return res;
	}
};
