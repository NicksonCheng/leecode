// solution
/*
1. brutal force, 每個i,j都去看rectangle area, O(n^2)
2. monotonic stack, 問題, 目前在於找尋柱子的left smaller, right smaller index,
用monotonic stack好的處在於, 我們可以直接遇到right smaller, 之後再pop stack
作為left smaller即可, 當stack為空的時候,代表自己就是最小的柱子, 那width就是i



*/
class Solution {
  public:
	int largestRectangleArea(vector<int> &heights) {
		// push 0 to the end to calculate max_area at final
		heights.push_back(0);
		stack<int> hist_idx;
		int max_area = 0;
		for (int i = 0; i < heights.size(); ++i) {
			int cur_h = heights[i];

			// 遇到比自己更矮的
			while (!hist_idx.empty() && heights[hist_idx.top()] > cur_h) {

				// 目前這根pop出來的 "最高柱子", 必須結算他的最大面積
				int height = heights[hist_idx.top()];
				hist_idx.pop();

				// 尋找left/ right smaller
				int width = 0;
				if (hist_idx.empty()) {
					// 左邊沒有比這根柱子還矮的柱子了！, 這根柱子為最小height,
					width = i;
				} else {
					// i 為 right smaller
					// hist_idx.top() - 1 為left smaller
					width = i - hist_idx.top() - 1;
				}
				max_area = max(max_area, height * width);
			}

			hist_idx.push(i);
		}
		return max_area;
	}
};