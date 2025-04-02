// hint
/*
    1. 我們從border 出發看誰能夠流到這個cell
    2. 兩個ocean都有hashset, 比對相同的cell return
*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
		if (heights.empty())
			return {};
		int n = heights.size();
		int m = heights[0].size();
		vector<vector<int>> pacific(n, vector<int>(m, 0));
		vector<vector<int>> atlantic(n, vector<int>(m, 0));
		vector<vector<int>> res;
		for (int i = 0; i < n; ++i) {
			dfs(heights, pacific, i, 0, INT_MIN);
			dfs(heights, atlantic, i, m - 1, INT_MIN);
		}
		for (int j = 0; j < m; ++j) {
			dfs(heights, pacific, 0, j, INT_MIN);
			dfs(heights, atlantic, n - 1, j, INT_MIN);
		}
		for (int i = 0; i < heights.size(); ++i) {
			for (int j = 0; j < heights[i].size(); ++j) {
				if (pacific[i][j] == 1 && atlantic[i][j] == 1)
					res.push_back({i, j});
			}
		}
		return res;
	}

  private:
	void dfs(vector<vector<int>> &heights, vector<vector<int>> &ocean, int row,
	         int col, int last_h) {
		if (row < 0 || col < 0 || row >= heights.size() ||
		    col >= heights[0].size() || ocean[row][col] == 1 ||
		    heights[row][col] < last_h)
			return;
		ocean[row][col] = 1;
		vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

		for (auto &dir : dirs) {
			dfs(heights, ocean, row + dir[0], col + dir[1], heights[row][col]);
		}
	}
};
