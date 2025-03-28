// proficient
/*
    bottom-up, 每一步都是i+1, j+1 的總和
*/
class Solution {
  public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> path(m, vector<int>(n, 0));

		for (int i = m - 1; i >= 0; --i) {
			for (int j = n - 1; j >= 0; --j) {
				if (i == m - 1 && j == n - 1) {
					path[m - 1][n - 1] = 1;
					continue;
				}
				if (i + 1 < m)
					path[i][j] += path[i + 1][j];
				if (j + 1 < n)
					path[i][j] += path[i][j + 1];
			}
		}
		return path[0][0];
	}
};
