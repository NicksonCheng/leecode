
/*
    移動比較低的水柱, 因為那是保底目前最大的高度
*/
class Solution {
  public:
	int maxArea(vector<int> &heights) {
		int l = 0;
		int r = heights.size() - 1;

		int max_area = 0;
		while (l <= r) {

			if (heights[l] < heights[r]) {
				int cur_area = (r - l) * heights[l];
				if (cur_area > max_area)
					max_area = cur_area;
				++l;
			} else {
				int cur_area = (r - l) * heights[r];
				if (cur_area > max_area)
					max_area = cur_area;
				--r;
			}
		}
		return max_area;
	}
};
