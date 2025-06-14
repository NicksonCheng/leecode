/*
    110100 (52), left
    110101 (53)
    110110 (54)
    110111 (55), right

    從舉例可以看到, 因為是連續數字, 中間bit 是不斷在變動的, 關鍵在於找到(left,
   right 的prefix digits) 這樣就可以確保prefix這邊依然還是相同的digit,
   再根據shift的次數shift回去即可 O(right - left)
*/
class Solution {
  public:
	int rangeBitwiseAnd(int left, int right) {
		int shift = 0;

		while (left != right) {
			left >>= 1;
			right >>= 1;
			++shift;
		}
		right <<= shift;
		return right;
	}
};