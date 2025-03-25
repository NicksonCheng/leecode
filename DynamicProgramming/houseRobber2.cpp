#include <iostream>
#include <vector>
using namespace std;

/*
    因為是環形hourse, 所以分成0~n-1, 1~n 去做, 並找出最大值
    就想成有兩個小偷偷0~n-1, 1~n, 看誰偷的比較多
*/
class Solution {
  public:
	vector<vector<int>> table;
	int rob(vector<int> &nums) {
		int n = nums.size();
		if (n == 1)
			return nums[0];
		table.resize(n, vector<int>(2, -1));

		return max(dfs(nums, 0, 0), dfs(nums, 1, 1));
	}
	int dfs(vector<int> &nums, int i, int robber_id) {
		int end = robber_id == 0 ? nums.size() - 1 : nums.size();
		if (i >= end) {
			return 0;
		}
		if (table[i][robber_id] != -1)
			return table[i][robber_id];
		table[i][robber_id] = max(dfs(nums, i + 1, robber_id),
		                          nums[i] + dfs(nums, i + 2, robber_id));
		return table[i][robber_id];
	}
};
