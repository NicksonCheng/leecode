// solution
/* two pointer 進階版, top <= bottom, left <= right, 每次做完都往內縮 */
class Solution {
  public:
	vector<int> spiralOrder(vector<vector<int>> &matrix) {
		if (matrix.empty())
			return {};

		int top = 0;
		int bottom = matrix.size() - 1;
		int left = 0;
		int right = matrix[0].size() - 1;

		vector<int> res;

		while (top <= bottom && left <= right) {
			// 左到右
			for (int i = left; i <= right; ++i)
				res.push_back(matrix[top][i]);
			++top;

			// 上到下
			for (int i = top; i <= bottom; ++i)
				res.push_back(matrix[i][right]);
			--right;

			// 右到左（確認是否還有剩下的行）
			if (top <= bottom) {
				for (int i = right; i >= left; --i)
					res.push_back(matrix[bottom][i]);
				--bottom;
			}

			// 下到上（確認是否還有剩下的列）
			if (left <= right) {
				for (int i = bottom; i >= top; --i)
					res.push_back(matrix[i][left]);
				++left;
			}
		}

		return res;
	}
};
