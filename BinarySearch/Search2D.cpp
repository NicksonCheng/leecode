#include <iostream>
#include <vector>
using namespace std;
class Solution {
  public:
	bool searchMatrix(vector<vector<int>> &matrix, int target) {
		int rows = matrix.size();
		int cols = matrix[0].size();
		int l = 0, r = rows * cols - 1;

		while (l <= r) {
			/* code */
			int m = (l + r) / 2;
			int m_row = m / cols;
			int m_col = m % cols;
			cout << l << " " << m << " " << r << endl;
			if (target > matrix[m_row][m_col]) {
				l = m_row * cols + m_col + 1;
			} else if (target < matrix[m_row][m_col]) {
				r = m_row * cols + m_col - 1;
			} else {
				return true;
			}
		}

		return false;
	}
};

int main() {
	Solution sol;
	vector<vector<int>> nums = {
	    {1, 2, 4, 8}, {10, 11, 12, 13}, {14, 20, 30, 40}};
	cout << sol.searchMatrix(nums, 14) << endl;

	return 0;
}