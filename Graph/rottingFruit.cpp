#include <iostream>
#include <queue>
using namespace std;
/*
    time complexity O(m*n)
    基本上都知道怎麼做, 就是細節問題
    1. 計算fresh_cnt, 跟看rotten在哪push進去queue
    2. BFS search 去計算rotten level

    錯誤地方
    1. 想用(-1,-1) 當柵欄去算rotten level-> TLE
    2. 忘記要設定visit(rotten設為2)
    3. 關鍵在於要用兩個loop, 第一個用來記錄目前rotten的個數,
   這樣才能計算下一次rotten level
*/
class Solution {
  public:
	int orangesRotting(vector<vector<int>> &grid) {
		int rotten_i = 0;
		int rotten_j = 0;
		int fresh_cnt = 0;
		queue<pair<int, int>> rotten_indices;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[i].size(); ++j) {
				if (grid[i][j] == 0)
					continue;
				if (grid[i][j] == 2) {
					rotten_indices.push({i, j});
				} else {
					++fresh_cnt;
				}
			}
		}
		int rotten_level = 0;
		int curr_rotten_cnt = rotten_indices.size();

		// 必須要加fresh_cnt >=0, 因為最後一次rotten會被算進去
		while (fresh_cnt >= 0 && !rotten_indices.empty()) {
			/* code */
			int curr_size = rotten_indices.size();
			for (int i = 0; i < curr_size; ++i) {
				pair<int, int> rotten = rotten_indices.front();
				int row = rotten.first;
				int col = rotten.second;
				vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
				int next_rotten_num = 0;
				for (int i = 0; i < dirs.size(); ++i) {
					int next_row = row + dirs[i][0];
					int next_col = col + dirs[i][1];
					if (next_row < 0 || next_col < 0 ||
					    next_row >= grid.size() || next_col >= grid[0].size() ||
					    grid[next_row][next_col] != 1)
						continue;
					// visit, set it rotten
					grid[next_row][next_col] = 2;
					rotten_indices.push({next_row, next_col});
					--fresh_cnt;
				}
				rotten_indices.pop();
			}
			++rotten_level;
		}
		return fresh_cnt == 0 ? rotten_level : -1;
	}
};
int main() {
	vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
	Solution sol;
	cout << sol.orangesRotting(grid) << endl;
}
