// proficient
/*
    BFS, 每次從目前可以打開的box 去拿取candies, keys, containedBoxes
    可以打開的push到queue
    不能打開的用set去存直到拿到key才push到open queue

    不斷loop 直到 queue為空

*/
class Solution {
  public:
	int maxCandies(vector<int> &status, vector<int> &candies,
	               vector<vector<int>> &keys,
	               vector<vector<int>> &containedBoxes,
	               vector<int> &initialBoxes) {
		queue<int> open_boxes;
		unordered_set<int> close_boxes;
		int total_candies = 0;
		for (int &box : initialBoxes) {
			if (status[box] == 1) {
				// can open
				open_boxes.push(box);
			} else
				close_boxes.insert(box);
		}
		while (!open_boxes.empty()) {
			int size = open_boxes.size();

			for (int i = 0; i < size; ++i) {
				int cur_box = open_boxes.front();
				open_boxes.pop();
				total_candies += candies[cur_box];

				// if find i-th key, change i-th status(can open now)
				for (int &key : keys[cur_box]) {
					status[key] = 1;
					if (close_boxes.count(key) > 0) {
						close_boxes.erase(key);
						open_boxes.push(key);
					}
				}
				for (int &box : containedBoxes[cur_box]) {
					if (status[box] == 1) {
						// can open
						open_boxes.push(box);
					} else
						close_boxes.insert(box);
				}
			}
		}
		return total_candies;
	}
};