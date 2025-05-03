/*1. brutal force, 每個number都去rotate跟自己不同的數字, O(n^2)
  2. greedy, 直接rotate top/bottom出現最多的, 如果都還沒統一就是-1
*/
class Solution {
  public:
	int countDomino(vector<int> &dominos) {
		vector<int> domino_count(6, 0);

		int max_count = 0;
		int max_domino_idx = 0;
		for (int &d : dominos) {
			++domino_count[d - 1];
			if (domino_count[d - 1] > max_count) {
				max_count = domino_count[d - 1];
				max_domino_idx = d;
			}
		}
		return max_domino_idx;
	}
	int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
		int max_domino_idx = countDomino(tops);
		int top_rotate = 0;
		int bottom_rotate = 0;
		for (int i = 0; i < tops.size(); ++i) {
			// rotate
			if (tops[i] != max_domino_idx) {
				// rotatable
				if (bottoms[i] == max_domino_idx)
					++top_rotate;
				else {
					top_rotate = -1;
					break;
				}
			}
		}
		max_domino_idx = countDomino(bottoms);
		for (int i = 0; i < bottoms.size(); ++i) {
			// rotate
			if (bottoms[i] != max_domino_idx) {
				// rotatable
				if (tops[i] == max_domino_idx)
					++bottom_rotate;
				else {
					bottom_rotate = -1;
					break;
				}
			}
		}
		if (top_rotate >= 0 && bottom_rotate >= 0)
			return min(top_rotate, bottom_rotate);
		else if (bottom_rotate >= 0) {
			return bottom_rotate;
		} else if (top_rotate >= 0)
			return top_rotate;
		else
			return -1;
	}
};

/*
    正解版: 直接看top[0], bottom[0] 作為target能否全部翻轉,
*/
class Solution {
  public:
	// 檢查是否能讓所有位置的值都變成 target，並回傳最少旋轉次數
	int check(int target, vector<int> &tops, vector<int> &bottoms) {
		int rotate_top = 0;    // 從 top 旋轉到 target 的次數
		int rotate_bottom = 0; // 從 bottom 旋轉到 target 的次數

		for (int i = 0; i < tops.size(); ++i) {
			// 如果該位置的 top 和 bottom 都不是 target，無法統一，直接回傳 -1
			if (tops[i] != target && bottoms[i] != target) {
				return -1;
			}
			// 如果 top 不是 target，就必須從 bottom 旋轉上來
			else if (tops[i] != target) {
				++rotate_top;
			}
			// 如果 bottom 不是 target，就必須從 top 旋轉下來
			else if (bottoms[i] != target) {
				++rotate_bottom;
			}
			// 如果兩邊都是 target，這格不需要旋轉
		}

		// 回傳兩種方式中需要旋轉次數較少的那個
		return min(rotate_top, rotate_bottom);
	}

	int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
		// 嘗試以 tops[0] 作為統一值的情況
		int res = check(tops[0], tops, bottoms);

		// 如果成功，或 tops[0] == bottoms[0]（只需檢查一個），直接回傳
		if (res != -1 || tops[0] == bottoms[0])
			return res;

		// 否則，試試看以 bottoms[0] 作為統一值的情況
		return check(bottoms[0], tops, bottoms);
	}
};
