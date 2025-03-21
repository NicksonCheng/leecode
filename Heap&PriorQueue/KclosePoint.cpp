#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
  public:
	vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
		for (int i = 0; i < points.size(); ++i) {
			int x = points[i][0];
			int y = points[i][1];
			float distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << distance << endl;
			pair<int, int> POI = {x, y};
			max_heap.push({distance, POI});

			if (max_heap.size() > k)
				max_heap.pop();
		}
		vector<vector<int>> res;
		while (!max_heap.empty()) {
			pair<int, int> coordinate = max_heap.top().second;
			vector<int> point = {coordinate.first, coordinate.second};
			res.push_back(point);
			max_heap.pop();
		}
		return res;
	}

  private:
	// min_heap with only k_size
	priority_queue<pair<float, pair<int, int>>> max_heap;
};

int main() {
	vector<vector<int>> points = {{-5, 4}, {-6, -5}, {4, 6}};
	Solution sol;
	vector<vector<int>> res = sol.kClosest(points, 2);

	for (int i = 0; i < res.size(); ++i) {
		cout << res[i][0] << " " << res[i][1] << endl;
	}
	return 0;
}